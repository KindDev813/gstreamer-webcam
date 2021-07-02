/* Aravis - Digital camera library
 *
 * Copyright © 2009-2019 Emmanuel Pacaud
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 * Author: Emmanuel Pacaud <emmanuel@gnome.org>
 */

#ifndef ARV_MISC_H
#define ARV_MISC_H

#if !defined (ARV_H_INSIDE) && !defined (ARAVIS_COMPILATION)
#error "Only <arv.h> can be included directly."
#endif

#include <arvtypes.h>

G_BEGIN_DECLS

void 		arv_copy_memory_with_endianness	(void *to, size_t to_size, guint to_endianness,
						 void *from, size_t from_size, guint from_endianness);

void * 		arv_decompress 			(void *input_buffer, size_t input_size, size_t *output_size);

const char * 	arv_pixel_format_to_gst_caps_string 		(ArvPixelFormat pixel_format);
ArvPixelFormat 	arv_pixel_format_from_gst_caps 			(const char *name, const char *format, int bpp, int depth);
const char * 	arv_pixel_format_to_gst_0_10_caps_string 	(ArvPixelFormat pixel_format);
ArvPixelFormat 	arv_pixel_format_from_gst_0_10_caps 		(const char *name, int bpp, int depth, guint32 fourcc);

const char *	arv_vendor_alias_lookup		(const char *vendor);

G_END_DECLS

#endif
