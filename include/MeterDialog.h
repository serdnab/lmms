/*
 * MeterDialog.h - dialog for entering meter settings
 *
 * Copyright (c) 2006-2008 Danny McRae <khjklujn/at/yahoo.com>
 * Copyright (c) 2009 Tobias Doerffel <tobydox/at/users.sourceforge.net>
 *
 * This file is part of LMMS - https://lmms.io
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */

#ifndef LMMS_GUI_METER_DIALOG_H
#define LMMS_GUI_METER_DIALOG_H

#include <QWidget>

#include "ModelView.h"

namespace lmms::gui
{

class LcdSpinBox;


class MeterDialog : public QWidget, public ModelView
{
	Q_OBJECT
public:
	MeterDialog( QWidget * _parent, bool _simple = false );
	~MeterDialog() override = default;

	void modelChanged() override;


private:
	LcdSpinBox * m_numerator;
	LcdSpinBox * m_denominator;

} ;

} // namespace lmms::gui

#endif // LMMS_GUI_METER_DIALOG_H
