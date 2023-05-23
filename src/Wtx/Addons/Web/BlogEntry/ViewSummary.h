/**************************************************************************
###########################################################################
##
## $SHOWOFFDB_BEGIN_LICENSE$
## Copyright (C) 2011 Lorimark Solutions, LLC and/or its subsidiary(-ies).
##  All rights reserved.
##  Contact: Lorimark Solutions, LLC (info@showoff-db.org)
##
## This file is part of the Showoff Database Application Framework.
##
##  Commercial Usage
##  Licensees holding valid ShowoffDB Commercial licenses may use this file in
##   accordance with the ShowoffDB Commercial License Agreement provided with the
##   Software or, alternatively, in accordance with the terms contained in
##   a written agreement between you and Lorimark Solutions, LLC.
##
## GNU Lesser General Public License Usage
##  Alternatively, this file may be used under the terms of the GNU Lesser
##   General Public License version 2.1 as published by the Free Software
##   Foundation and appearing in the file LICENSE.LGPL included in the
##   packaging of this file.  Please review the following information to
##   ensure the GNU Lesser General Public License version 2.1 requirements
##   will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
##
## In addition, as a special exception, Lorimark Solutions, LLC gives
##  you certain additional rights.  These rights are described in the
##  Lorimark Solutions, LLC ShowoffDB LGPL Exception version 1.0, included in
##  the file LGPL_EXCEPTION.txt in this package.
##
## GNU General Public License Usage
##  Alternatively, this file may be used under the terms of the GNU
##   General Public License version 3.0 as published by the Free Software
##   Foundation and appearing in the file LICENSE.GPL included in the
##   packaging of this file.  Please review the following information to
##   ensure the GNU General Public License version 3.0 requirements will be
##   met: http://www.gnu.org/copyleft/gpl.html.
##
## If you have questions regarding the use of this file, please contact
##   Lorimark Solutions, LLC at info@showoff-db.org.
## $SHOWOFFDB_END_LICENSE$
##
#############################################################################
****************************************************************************/

#ifndef __WTX_WEB_BLOGENTRY_VIEWSUMMARY_H___
#define __WTX_WEB_BLOGENTRY_VIEWSUMMARY_H___

#include <Wt/WContainerWidget.h>

namespace Wt {
  class WStackedWidget;
}

namespace Wtx {

  namespace Dbo {
    class Session;
  }

  namespace Web {
    namespace BlogEntry {

/*!
** \brief Blog View Summary
**
** This view provides a paged-interface to the blog entries,
**  such that each published blog item is listed in the summary,
**  and the summary view is limited to some number of items
**  per page.  A set of pager buttons are provided for moving
**  forward and backward through the items.  Clicking on an
**  item causes that specific item to be opened.
**
** \image html ViewSummary.png
**
*/
class ViewSummary
: public Wt::WContainerWidget
{
  public:

    ViewSummary( Wtx::Dbo::Session * s );

    Wtx::Dbo::Session * session() const
    {
      return m_session;
    }

  private:

    void on_internalPathChanged();

    Wtx::Dbo::Session * m_session = nullptr;
    Wt::WStackedWidget * m_stack = nullptr;

}; // endclass ViewSummary

    } // endnamespace BlogEntry
  } // endnamespace Web
} // endnamespace Wtx

#endif // __WTX_WEB_BLOGENTRYVIEWSUMMARY_H___
