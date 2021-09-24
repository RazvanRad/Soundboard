#include <BluetoothWrapper.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <bluetooth/sdp.h>
#include <bluetooth/sdp_lib.h>
#include <sys/socket.h>
#include <unistd.h>

void start_socket(void (*handler)(int), int *active, int port)
{
    struct sockaddr_rc loc_addr = {0}, rem_addr = {0};
    char buf[1024] = {0};
    int s, client, bytes_read;
    socklen_t opt = sizeof(rem_addr);

    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    loc_addr.rc_family = AF_BLUETOOTH;
    loc_addr.rc_bdaddr = *BDADDR_ANY;
    loc_addr.rc_channel = (uint8_t)port;
    bind(s, (struct sockaddr *)&loc_addr, sizeof(loc_addr));

    listen(s, 1);

    client = accept(s, (struct sockaddr *)&rem_addr, &opt);

    ba2str(&rem_addr.rc_bdaddr, buf);
    //fprintf(stderr, "accepted connection from %s\n", buf);
    while (1)
    {
        memset(buf, 0, sizeof(buf));

        bytes_read = read(client, buf, sizeof(buf));
        if (bytes_read > 0)
        {
            //printf("received [%s]\n", buf);
            handler(buf[0]);
        }
    }

    // close connection
    close(client);
    close(s);
}