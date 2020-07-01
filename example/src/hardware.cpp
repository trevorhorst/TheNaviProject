#include "hardware/hardware.h"

/**
 * @brief Constructor
 */
Hardware::Hardware()
    : HardwareBase()
    , mIndexHtml( Resources::load( Resources::index_html, Resources::index_html_size ) )
    , mBundleJs( Resources::load( Resources::bundle_js, Resources::bundle_js_size ) )
    , mServer( mIndexHtml, mBundleJs )
    , mHeartbeatTimer( 1000, Timer::Type::INTERVAL, std::bind( &Hardware::heartbeat, this ) )
{
    // Add the individual commands
    addCommand( &mCmdHeartbeat );
    addCommand( &mCmdSystem );
    addCommand( &mCmdDateTime );
    addCommand( &mCmdServer );

    // Set the command handler and start the server
    mServer.setCommandHandler( getCommandHandler() );
    mServer.listen();

    mHeartbeatTimer.start();
}

/**
 * @brief Destructor
 */
Hardware::~Hardware()
{
    // Destruct things in the reverse order
    mHeartbeatTimer.stop();

    mServer.stop();
    Resources::unload( mIndexHtml );
    Resources::unload( mBundleJs );
}

/**
 * @brief Heartbeat for the hardware, update pertinant hardware information from
 * this method
 */
void Hardware::heartbeat()
{
}
