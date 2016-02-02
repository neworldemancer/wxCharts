/*
	Copyright (c) 2016 Xavier Leclercq

	Permission is hereby granted, free of charge, to any person obtaining a
	copy of this software and associated documentation files (the "Software"),
	to deal in the Software without restriction, including without limitation
	the rights to use, copy, modify, merge, publish, distribute, sublicense,
	and/or sell copies of the Software, and to permit persons to whom the
	Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
	THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
	IN THE SOFTWARE.
*/

/*
	Part of this file were copied from the Chart.js project (http://chartjs.org/)
	and translated into C++.

	The files of the Chart.js project have the following copyright and license.

	Copyright (c) 2013-2016 Nick Downie
	Released under the MIT license
	https://github.com/nnnick/Chart.js/blob/master/LICENSE.md
*/

#include "wxchartpoint.h"
#include <wx/pen.h>
#include <wx/brush.h>

wxChartPoint::wxChartPoint(wxDouble x,
						   wxDouble y, 
						   wxDouble radius,
						   unsigned int strokeWidth, 
						   const wxColor &strokeColor,
						   const wxColor &fillColor,
						   const wxString &tooltip)
	: wxChartElement(tooltip), m_position(x, y), m_radius(radius), 
	m_strokeWidth(strokeWidth), m_strokeColor(strokeColor),
	m_fillColor(fillColor)
{
}

bool wxChartPoint::HitTest(const wxPoint &point) const
{
	return false;
}

wxPoint2DDouble wxChartPoint::GetTooltipPosition() const
{
	return wxPoint2DDouble(0, 0);
}

void wxChartPoint::Draw(wxGraphicsContext &gc)
{
	wxGraphicsPath path = gc.CreatePath();
	path.AddArc(m_position.m_x, m_position.m_y, m_radius, 0, 2 * M_PI, false);
	path.CloseSubpath();

	wxBrush brush(m_fillColor);
	gc.SetBrush(brush);
	gc.FillPath(path);

	wxPen pen(m_strokeColor, m_strokeWidth);
	gc.SetPen(pen);
	gc.StrokePath(path);
}

const wxPoint2DDouble& wxChartPoint::GetPosition() const
{
	return m_position;
}

void wxChartPoint::SetPosition(wxDouble x, wxDouble y)
{
	m_position.m_x = x;
	m_position.m_y = y;
}

void wxChartPoint::SetPosition(wxPoint2DDouble position)
{
	m_position = position;
}
