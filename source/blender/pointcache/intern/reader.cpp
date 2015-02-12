/*
 * Copyright 2013, Blender Foundation.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "reader.h"
#include "util_error_handler.h"

extern "C" {
#include "DNA_scene_types.h"
}

namespace PTC {

Reader::Reader(Scene *scene, ID *id, PointCache *cache, ReaderArchive *archive) :
    m_error_handler(0),
    m_archive(archive),
    m_scene(scene),
    m_id(id),
    m_cache(cache)
{
}

Reader::~Reader()
{
	if (m_error_handler)
		delete m_error_handler;
}

void Reader::set_error_handler(ErrorHandler *handler)
{
	if (m_error_handler)
		delete m_error_handler;
	
	m_error_handler = handler;
}

bool Reader::valid() const
{
	return m_error_handler ? m_error_handler->max_error_level() >= PTC_ERROR_CRITICAL : true;
}

} /* namespace PTC */
