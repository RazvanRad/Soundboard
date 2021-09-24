#ifndef SOUNDBOARD_BLUETOOTH_LISTENER
#define SOUNDBOARD_BLUETOOTH_LISTENER

#include <IListener.hpp>

#include <thread>
#include <vector>

/**
 * Listens on a bluetooth socket for data represented as an integer
 */
class BluetoothListener : public IListener
{
private:
    std::thread bthread;
    int _active;
    int port;

public:
    /**
     * @param port The port that will be used by the socket
     */
    BluetoothListener(int port);

    /**
     * Starts a bluetooth socket on a separate thread
     * @param handler Whenever the socket receives data from the client this function will be called with the respective data
     */
    void start(Handler handler);

    /**
     * Stops the bluetooth socket and terminates the listener thread
     */
    void stop();

    /**
     * Initializes the bluetooth configuration.
     * Will run the following commands: \n
     * `sudo systemctl daemon-reload` \n
     * `sudo systemctl bluetooth restart` \n
     * `sudo hciconfig <device> piscan` \n
     *  where `<device`> is the first bluetooth device found (returned by `hcitool dev`)
     */
    int init();

    int isActive() const;
};

#endif