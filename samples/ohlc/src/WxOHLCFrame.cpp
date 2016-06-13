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

#include "WxOHLCFrame.h"
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/charts/wxcharts.h>

WxOHLCFrame::WxOHLCFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title)
{
	// Create a top-level panel to hold all the contents of the frame
	wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Create the data for the OHLC chart widget
    wxVector<wxString> labels;
    labels.push_back("02/02");
    labels.push_back("03/02");
    labels.push_back("04/02");
    labels.push_back("05/02");
    labels.push_back("06/02");
    labels.push_back("07/02");
    labels.push_back("08/02");
    labels.push_back("09/02");
    labels.push_back("10/02");

    wxVector<wxChartOHLCData> data;
    data.push_back(wxChartOHLCData(6, 10, 5, 8));
    data.push_back(wxChartOHLCData(7, 7.5, 6, 6.2));
    data.push_back(wxChartOHLCData(5, 6, 3, 4));
    data.push_back(wxChartOHLCData(3.5, 4.2, 3.2, 3.5));
    data.push_back(wxChartOHLCData(4, 7, 4, 5));
    data.push_back(wxChartOHLCData(4.5, 6, 4, 6));
    data.push_back(wxChartOHLCData(5, 7, 4.5, 7));
    data.push_back(wxChartOHLCData(7, 8, 5, 7.5));
    data.push_back(wxChartOHLCData(7.2, 8, 6, 6.5));

    wxOHLCChartData chartData(labels, data);

	// Create the OHLC chart widget from the constructed data
	wxOHLCChartCtrl* ohlcChartCtrl = new wxOHLCChartCtrl(panel, wxID_ANY, chartData,
		wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);

	// Set up the sizer for the panel
	wxBoxSizer* panelSizer = new wxBoxSizer(wxHORIZONTAL);
	panelSizer->Add(ohlcChartCtrl, 1, wxEXPAND);
	panel->SetSizer(panelSizer);

	// Set up the sizer for the frame
	wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
	topSizer->Add(panel, 1, wxEXPAND);
	SetSizerAndFit(topSizer);
}
