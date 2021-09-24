#ifndef SOUNDBOARD_LISTENER_H_
#define SOUNDBOARD_LISTENER_H_

typedef void(*Handler)(int);

/**
 * Generic interface for listeners
 * 
 */
class IListener
{
public:
    /**
     * Starts the listener. Must be a non-blocking call
     * @param handler The function that will be called when the listener detects input
     */
    virtual void start(Handler handler) = 0;

    /**
     * Stops the listener. Should clean up any resources used by the listener
     */
    virtual void stop() = 0;

    /**
     * Initializes the listener. Will be called before start
     */
    virtual int init() = 0;

    /**
     * Tells if the listener is active or not
     * @return 0 if init was successful, other value otherwise
     */
    virtual int isActive() const = 0;
};


#endif