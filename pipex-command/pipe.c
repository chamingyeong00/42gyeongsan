/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:04:17 by yeham             #+#    #+#             */
/*   Updated: 2023/04/02 21:42:12 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

char	**path_maker(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (ft_split2(envp[i] + 5, ':'));
		i++;
	}
	return (0);
}

char	*check_order(char **path, char *cmd)
{
	int		i;
	char	*find;

	// X_OK : 파일 존재 여부, 실행/검색 권한 여부
	// 성공 시 0, 실패 시 -1
	if (access(cmd, X_OK) == 0) // 명령어가 절대경로로 들어올 경우 체크 ex) /bin/ls
		return (cmd);
	i = 0;
	while (path[i])
	{
		find = ft_strjoin(path[i], cmd);
		if (access(find, X_OK) == 0) //절대 경로가 아니라면 $PATH의 값이랑 strjoin을 하여 여부 확인
			return (find);
		free(find);
		i++;
	}
	return (0);
}

void	first_child(t_data *all, int *fd, char *argv[], char *envp[])
{
	// 0644 		0 8진수 표기법
	// 				소유자(User) 6(4읽기+2쓰기)
	// 			    그룹자(Group) 4(4)
	// 			    기타(Others) 4(4)
	all->infile = open(argv[1], O_RDONLY, 0644); //infile을 옵션에 맞게 open
	if (all->infile == -1)
		perror("file open error"); // open에 실패 시 perror
	all->order1 = check_order(all->path, all->cmd1[0]); // 1번 char **의 명령어 중 0번 인덱스 값이 path에 있는지 여부 확인
	close(fd[0]); // 안쓰는 파이프의 fd[0]을 닫기기
	if (dup2(all->infile, 0) == -1) //표준 입력인 '0'을 open한 fd를 가리키게게 변경하여 파일의 내용을 입력으로 사용
		just_error("dup error"); // perror를 출력 후 exit하는 함수
	if (dup2(fd[1], 1) == -1) // 표준출력인 '1'을 파이프의 fd[1]을 가리키게 변경하여 파일의 내용을 파이프에 담아넣음
		just_error("dup error");
	close(fd[1]);
	close(all->infile); // dup2로 표준입력과 표준출력이 가르키는 값을 변경했으니 안쓰게 되어 닫아줍니다.
	if (execve(all->order1, all->cmd1, envp) == -1) //exec 함수를 활용하여 실행
		just_error("exec error");
}

void	last_child(t_data *all, int *fd, char *argv[], char *envp[])
{
	// O_RDONLY : 파일을 읽기 전용으로 open (Read Only)
	// O_RDWR : 파일을 쓰기와 읽기용으로 open (Read & Write)
	// O_CREAT : 파일이 없으면 생성한다. 이 플래그를 명시하면, open 함수에 Permission 정보를 추가로 더 받아야 하고 파일이 존재하면 해당 파일을 열어줍니다.
	// O_TRUNC : 파일이 이미 존재하고 write-only, read-write 모드로 열 수 있는 경우, 파일 사이즈를 0으로 초기화 시킵니다
	all->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644); //outfile을 옵션에 맞게 open
	if (all->outfile == -1)
		just_error("file open error"); // open에 실패 시 perror 후 exit
	all->order2 = check_order(all->path, all->cmd2[0]); // 2번 char **의 명령어 중 0번 인덱스 값이 path에 있는 여부 확인
	close(fd[1]); // 안쓰는 파이프의 fd[1]을 닫기
	if (dup2(all->outfile, 1) == -1) // 표준 출력인 '1'을 open한 fd를 가르키게 변경하여 파이프의 내용을 파일에 출력
		just_error("dup error");
	if (dup2(fd[0], 0) == -1) // 표준입력인 '0'을 파이프의 fd[0]를 가리키게 변경하여 파이프의 내용을 입력으로 받음
		just_error("dup error");
	close(fd[0]);
	close(all->outfile); // dup2로 표준입력과 표준출력이 가리키는 값을 변경했으니 안쓰게 되어 닫아줍니다.
	if (execve(all->order2, all->cmd2, envp) == -1) //evec 함수를 활용하여 실행
		just_error("exec error");
}

void	pipe_maker(t_data *all, char *argv[], char *envp[])
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	pipe(fd); // 파이프 생성 fd[0], fd[1]
	pid2 = -1;
	pid1 = fork(); // 자식 프로세스1 생성
	if (pid1 == -1)
		just_error("pid error");
	else if (pid1 == 0)
		first_child(all, fd, argv, envp); //자식 프로세스에서 명령어 실행 및 fd값 변경
	else
	{
		pid1 = fork(); // 자식프로세스2 생성
		if (pid1 == -1)
			just_error("pid error");
		else if (pid1 == 0)
			last_child(all, fd, argv, envp); // 자식 프로레스에서 명령어 실행 및 fd값 변경
		else
		{
			// fd[0] : 파이프의 출구로 데이터를 입력받은 fd가 담기고, fd[1]에는 파이프의 입구로 데이터를 출력할 수 있는 fd가 담김
			// fd[0]은 다른 프로세스에서 전달받은 데이터를 read하는 파이프 입구가 되고 fd[1]은 다른 프로세스로 전달할 데이터를 write 하는 파이프 출구가 된다
			close(fd[0]);
			close(fd[1]); // 자식간의 통신을 위해 부모 프로세스는 파이프의 fd를 닫아줍니다.
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0); // 부모 프로세스는 fd값을 닫은 상태에서 자식 프로세스가 끝날 때 까지 대기
		}
	}
}

void	allfree(char **all)
{
	int	i;

	i = 0;
	while (all[i])
	{
		free(all[i]);
		i++;
	}
	free(all);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	all;

	if (argc != 5)
		just_error("input count");
	all.cmd1 = ft_split(argv[2], ' ');
	all.cmd2 = ft_split(argv[3], ' ');
	all.path = path_maker(envp);
	pipe_maker(&all, argv, envp);
	allfree(all.path);
	allfree(all.cmd1);
	allfree(all.cmd2);
	return (0);
}
