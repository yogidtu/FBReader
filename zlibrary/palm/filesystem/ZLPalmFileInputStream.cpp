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

#include "ZLPalmFileInputStream.h"

ZLPalmFileInputStream::ZLPalmFileInputStream(const std::string &name) : myName(name) {
	//myFile = 0;
}

ZLPalmFileInputStream::~ZLPalmFileInputStream() {
	close();
}

bool ZLPalmFileInputStream::open() {
	/*
	close();
	myFile = fopen(myName.c_str(), "rb");
	return myFile != 0;
	*/
	return false;
}

int ZLPalmFileInputStream::read(char *buffer, int maxSize) {
	//return fread(buffer, 1, maxSize, myFile);
	return 0;
}

void ZLPalmFileInputStream::close() {
	/*
	if (myFile != 0) {
		fclose(myFile);
		myFile = 0;
	}
	*/
}

void ZLPalmFileInputStream::seek(int offset) {
}

int ZLPalmFileInputStream::offset() const {
	return 0;
}
