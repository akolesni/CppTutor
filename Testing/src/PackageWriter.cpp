#include "PackageWriter.h"
using DVS_IMPORTANT = std::pair<std::string, std::string>;
namespace defines
{
    std::string p_asset_map_name = "ASSETMAP.xml";
}

void neu::PackageWriter::CreateDestinationDir( Common::Path const& rDestinationPath )
{
    try
    {
        // Create the directory if it does not exist yet.
        if( m_fileSystemUtility->Exists( rDestinationPath ) && m_fileSystemUtility->IsDirectory( rDestinationPath ) )
        {
            if( m_fileSystemUtility->Exists( rDestinationPath / defines::p_asset_map_name ) )
            {
                throw exception::InvalidArgument( "The specified directory already contains a Package." );
            }
        }
        else
        {
            DVS_IMPORTANT( "PackageWriter", "The specified package directory does not exist. Creating directory." );
            m_fileSystemUtility->CreateDirectory( rDestinationPath );
        }
    }
    catch( std::filesystem::filesystem_error const& rEx )
    {
        throw exception::RuntimeError( std::string( "Writing package failed. Failed to create the package directory: " ) + rEx.what() );
    }
}

void old::PackageWriter::CreateDestinationDir( std::filesystem::path const& rDestinationPath )
{
    try
    {
        // Create the directory if it does not exist yet.
        if( std::filesystem::exists( rDestinationPath ) && std::filesystem::is_directory( rDestinationPath ) )
        {
            if( std::filesystem::exists( rDestinationPath / defines::p_asset_map_name ) )
            {
                throw exception::InvalidArgument( "The specified directory already contains a Package." );
            }
        }
        else
        {
            DVS_IMPORTANT( "PackageWriter", "The specified package directory does not exist. Creating directory." );
            std::filesystem::create_directories( rDestinationPath );
        }
    }
    catch( std::filesystem::filesystem_error const& rEx )
    {
        throw exception::RuntimeError( std::string( "Writing package failed. Failed to create the package directory: " ) + rEx.what() );
    }
}
