#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) {

	openlog("writer", 0, LOG_USER);
	
	if (argc != 3) {
		syslog(LOG_ERR, "Invalid number of arguments. Expected 2, got %d.", argc - 1);
		fprintf(stderr, "Usage: %s <writepath> <writestr>\n", argv[0]);
		return 1;
	}
	
	const char* file = argv[1];
	const char* str = argv[2];
	
	int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	
	if (fd == -1) {
		syslog(LOG_ERR, "Error opening file %s: %s", file, strerror(errno));
		return 1;
	}
	
	syslog(LOG_DEBUG, "Writing %s to %s", str, file);
	
	ssize_t bytes = write(fd, str, strlen(str));
	
	if (bytes == -1) {
		syslog(LOG_ERR, "Error writing to file %s: %s", file, strerror(errno));
		close(fd);
		return 1;
	} 
	
	else if ((size_t)bytes != strlen(str)) {
		syslog(LOG_ERR, "Partial write to file %s. Expected to write %zu bytes, but wrote %zd.", file, strlen(str), bytes);
		close(fd);
		return 1;
	}
	
	close(fd);
	closelog();
	
	return 0;

}
