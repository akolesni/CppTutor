#include "PackageWriter.h"

void PackageWriter::CreateDestinationDir( Common::Path const& rDestinationPath )
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
    catch( boost::filesystem::filesystem_error const& rEx )
    {
        throw exception::RuntimeError( std::string( "Writing package failed. Failed to create the package directory: " ) + rEx.what() );
    }
}