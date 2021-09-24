#ifndef SOUNDBOARD_H_
#define SOUNDBOARD_H_

#include <chrono>
#include <thread>

#include <Config.hpp>
#include <SoundManager.hpp>

/**
 * @brief Class used for initialize and run the application
 * 
 */
class SoundBoard
{
private:
    Config configFile;         // the place where data from config.json are stored
    SoundManager audioManager; // object used for playing sound on different devices

public:
    /**
     * @brief Construct a new Sound Board object. Does nothing.
     * 
     */
    SoundBoard();

    /**
     * @brief Initialize components
     * 
     * @param file - path for config.json
     */
    void init(std::string &file);

    /**
     * @brief Run infite until the application is closed
     * 
     */
    void run();
};

#endif