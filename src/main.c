#include <time.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char *const argv[]) {
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0) return 1;

	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr));

	server_addr.sin_family = AF_INET;  // i'm sorry ipv6 :(
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(1337);

	if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))) return 1;
	if (listen(server_fd, 16)) return 1;

	if (fork() == 0) {
		while (1) {
			int client_fd = accept(server_fd, NULL, NULL);
			if (client_fd < 0) return 1;
			time_t now = time(NULL);
			struct tm *tm_struct = localtime(&now);
			char time[6];
			int time_len = snprintf(time, 6, "%0.2d%0.2d\n", tm_struct->tm_hour, tm_struct->tm_min);
			write(client_fd, time, time_len);
			close(client_fd);
		}
	} else {
		puts("Running in the background");
		return 0;
	}

	return 1;
}
