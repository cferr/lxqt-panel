/*
 * <one line to give the library's name and an idea of what it does.>
 * Copyright (C) 2013  <copyright holder> <email>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef XDGCACHEDMENU_H
#define XDGCACHEDMENU_H

#include <menu-cache/menu-cache.h>
#include <QMenu>

class QEvent;
class QMouseEvent;

class XdgCachedMenu : public QMenu
{
    Q_OBJECT
public:
    XdgCachedMenu(QWidget* parent = NULL);
    XdgCachedMenu(MenuCache* menuCache, QWidget* parent);
    virtual ~XdgCachedMenu();

protected:
    bool event(QEvent* event);

private:
    void addMenuItems(QMenu* menu, MenuCacheDir* dir);
    void handleMouseMoveEvent(QMouseEvent *event);

private Q_SLOTS:
    void onItemTrigerred();
    void onAboutToShow();

private:
    QPoint mDragStartPosition;
};

class XdgCachedMenuAction: public QAction
{
    Q_OBJECT
public:
    explicit XdgCachedMenuAction(MenuCacheItem* item, QObject* parent = 0);
    virtual ~XdgCachedMenuAction();

    MenuCacheItem* item() const {
      return item_;
    }

    void updateIcon();

private:
    MenuCacheItem* item_;
};


#endif // XDGCACHEDMENU_H
