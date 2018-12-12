#ifndef __WINDOWS_TEXT_FILE_IO_HPP_
#define __WINDOWS_TEXT_FILE_IO_HPP_

#include <stdint.h>
#include <stdio.h>

#include "../../IFile.hpp"


namespace DadEngine::Core
{
    class String;
	// Use windows IO stuff ?

	struct WindowsTextFile : public IFile
	{
        WindowsTextFile (const char *_InFilePath, IOModeFlag _InIOMode);
		
		~WindowsTextFile ();


		uint8_t OpenRead (const char *_InFilePath) override final;

        uint8_t Read (uint8_t *_InDst, size_t _InBytesToRead) override final;

		uint8_t Read (String &_InDst) override final;
		

		uint8_t OpenWrite (const char *_InFilePath) override final;

		uint8_t Write (uint8_t *_InSrc, size_t _InBytesToWrite) override final;

		uint8_t Write (String &_InDst) override final;

		void Close () override final;

		size_t Size () override final;

		FILE* m_fileHandle = nullptr;
	};

	using PlatformTextFile = WindowsTextFile;
}

#endif //!__WINDOWS_TEXT_FILE_IO_HPP_