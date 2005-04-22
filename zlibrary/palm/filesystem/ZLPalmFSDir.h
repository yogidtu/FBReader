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

#ifndef __ZLPALMFSDIR_H__
#define __ZLPALMFSDIR_H__

#include <abstract/ZLFSDir.h>

class ZLPalmFSDir : public ZLFSDir {

public:
	ZLPalmFSDir(const std::string &name) : ZLFSDir(name) {}

	void createPhysicalDirectory();

	void collectSubDirs(std::vector<std::string> &names, bool includeSymlinks);
	void collectFiles(std::vector<std::string> &names, bool includeSymlinks);

protected:
	std::string delimiter() const { return "/"; }
};

#endif /* __ZLPALMFSDIR_H__ */
