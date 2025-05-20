#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork 실패");
        return 1;
    }
    else if (pid == 0) {
        // 자식 프로세스
        sleep(1);  // 부모가 종료될 시간을 주기 위해 잠시 대기
        printf("자식 프로세스: PID = %d, 부모 PID = %d\n", getpid(), getppid());
    }
    else {
        // 부모 프로세스
        printf("부모 프로세스: PID = %d, 자식 PID = %d\n", getpid(), pid);
        wait(NULL);  // 자식이 종료될 때까지 기다림
    }

    return 0;
}
