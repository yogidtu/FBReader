/*
 * Copyright (C) 2005 Nikolay Pultsin <geometer@mawhrin.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "ZLZipDir.h"
#include "ZipHeader.h"
#include "ZLFSManager.h"
#include "ZLInputStream.h"

void ZLZipDir::collectFiles(std::vector<std::string> &names, bool) {
	ZLInputStream *stream = ZLFSManager::instance().createInputStream(name());
	if (stream == 0) {
		return;
	}

	if (stream->open()) {
		ZipHeader header;
		while (header.readFrom(*stream)) {
			char *buffer = new char[header.NameLength];
			if ((unsigned int)stream->read(buffer, header.NameLength) == header.NameLength) {
				std::string entryName;
				entryName.append(buffer, header.NameLength);
				names.push_back(entryName);
			}
			delete[] buffer;
			stream->seek(header.ExtraLength + header.CompressedSize);
			if (header.Flags & 0x04) {
				stream->seek(12);
			}
		}
		stream->close();
	}
	delete stream;
}
