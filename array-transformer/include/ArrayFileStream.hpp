#pragma once

#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>

namespace ng
{
	class ArrayFileStream
	{
	public:
		explicit ArrayFileStream(const char* filePath)
			: fileName(filePath)
		{
			fs.open(filePath);
		}

		~ArrayFileStream() { fs.close(); }

		ArrayFileStream(const ArrayFileStream&) = delete;
		ArrayFileStream(ArrayFileStream&&) = default;

		ArrayFileStream& operator=(const ArrayFileStream&) = delete;
		ArrayFileStream& operator=(ArrayFileStream&&) = default;

		inline const bool IsValid() const { return fs.is_open(); }

		bool ReadLine(String& line)
		{
			if (IsValid())
			{
				return static_cast<bool>(std::getline(fs, line, ','));
			}
			return false;
		}

		char ReadChar()
		{
			if (IsValid())
			{
				return fs.get();
			}
			return '\n';
		}

	private:
		const char* fileName;
		std::ifstream fs;
	};
}