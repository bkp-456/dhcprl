//
// Created by Hugo Freire on 2017-08-23.
//

#ifndef DHCPRL_UNIX_H
#define DHCPRL_UNIX_H

#include <sys/queue.h>

struct cli_request {
    int sock_fd;
    LIST_ENTRY(cli_request) requests;
    unsigned char *output_buffer;
    int output_buffer_offset;
    int output_buffer_len;
};

LIST_HEAD(cli_request_list, cli_request) cli_requests;

void process_socket_request(struct cli_request *cli_request);

int open_unix_socket(const char *path);

#endif //DHCPRL_UNIX_H
