#ifndef SOUNDBOARD_BLUETOOTH_WRAPPER_H_
#define SOUNDBOARD_BLUETOOTH_WRAPPER_H_

#ifdef __cplusplus
extern "C"
{
#endif

    void start_socket(void (*handler)(int), int *active);

#ifdef __cplusplus
};
#endif

#endif