/* ATK -  Accessibility Toolkit
 * Copyright 2001 Sun Microsystems Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __ATK_COMPONENT_H__
#define __ATK_COMPONENT_H__

#include <atk/atkobject.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * The AtkComponent interface should be supported by any object that is 
 * rendered on the screen. The interface provides the standard mechanism 
 * for an assistive technology to determine and set the graphical
 * representation of an object.
 */

#define ATK_TYPE_COMPONENT                    (atk_component_get_type ())
#define ATK_IS_COMPONENT(obj)                 G_TYPE_CHECK_INSTANCE_TYPE ((obj), ATK_TYPE_COMPONENT)
#define ATK_COMPONENT(obj)                    G_TYPE_CHECK_INSTANCE_CAST ((obj), ATK_TYPE_COMPONENT, AtkComponent)
#define ATK_COMPONENT_GET_IFACE(obj)          (G_TYPE_INSTANCE_GET_INTERFACE ((obj), ATK_TYPE_COMPONENT, AtkComponentIface))

#ifndef _TYPEDEF_ATK_COMPONENT_
#define _TYPEDEF_ATK_COMPONENT_
typedef struct _AtkComponent AtkComponent;
#endif
typedef struct _AtkComponentIface  AtkComponentIface;

typedef void (*AtkFocusHandler) (AtkObject*, gboolean);


struct _AtkComponentIface
{
  GTypeInterface parent;

  guint          (* add_focus_handler)  (AtkComponent    *component,
                                         AtkFocusHandler handler);
  gboolean       (* contains)           (AtkComponent           *component,
                                         gint                   x,
                                         gint                   y);

  AtkObject*    (* get_accessible_at_point)  (AtkComponent     *component,
                                         gint                   x,
                                         gint                   y);
  void          (* get_extents)         (AtkComponent          *component,
                                         gint                  *x,
                                         gint                  *y,
                                         gint                  *width,
                                         gint                  *height);
  void                     (* get_position)     (AtkComponent   *component,
                                                 gint           *x,
                                                 gint           *y);
  void                     (* get_position_on_screen)   (AtkComponent   *component,
                                                         gint           *root_x,
                                                         gint           *root_y);
  void                     (* get_size)                 (AtkComponent   *component,
                                                         gint           *width,
                                                         gint           *height);
  void                     (* grab_focus)               (AtkComponent   *component);
  void                     (* remove_focus_handler)      (AtkComponent  *component,
                                                          guint         handler_id);
  void                     (* set_extents)      (AtkComponent   *component,
                                                 gint           x,
                                                 gint           y,
                                                 gint           width,
                                                 gint           height);
  void                     (* set_position)     (AtkComponent   *component,
                                                 gint           x,
                                                 gint           y);
  void                     (* set_size)         (AtkComponent   *component,
                                                 gint           width,
                                                 gint           height);
};

GType atk_component_get_type ();

/* convenience functions */

guint                atk_component_add_focus_handler      (AtkComponent    *component,
                                                           AtkFocusHandler handler);
gboolean              atk_component_contains               (AtkComponent    *component,
                                                            gint            x,
                                                            gint            y);
AtkObject*            atk_component_get_accessible_at_point(AtkComponent    *component,
                                                            gint            x,
                                                            gint            y);
void                  atk_component_get_extents            (AtkComponent    *component,
                                                            gint            *x,
                                                            gint            *y,
                                                            gint            *width,
                                                            gint            *height);
void                  atk_component_get_position           (AtkComponent    *component,
                                                            gint            *x,
                                                            gint            *y);
void                  atk_component_get_position_on_screen (AtkComponent    *component,
                                                            gint            *x,
                                                            gint            *y);
void                  atk_component_get_size               (AtkComponent    *component,
                                                            gint            *width,
                                                            gint            *height);
void                  atk_component_grab_focus             (AtkComponent    *component);
void                  atk_component_remove_focus_handler   (AtkComponent    *component,
                                                            guint           handler_id);
void                  atk_component_set_extents            (AtkComponent    *component,
                                                            gint            x,
                                                            gint            y,
                                                            gint            width,
                                                            gint            height);
void                  atk_component_set_position           (AtkComponent    *component,
                                                            gint            x,
                                                            gint            y);
void                  atk_component_set_size               (AtkComponent    *component,
                                                            gint            width,
                                                            gint            height);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __ATK_COMPONENT_H__ */
