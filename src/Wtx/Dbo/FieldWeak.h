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


#ifndef __WTX_DBO_FIELDWEAK_H_234e0174_6b7d_11e8_b503_fb1ef3651ec0__
#define __WTX_DBO_FIELDWEAK_H_234e0174_6b7d_11e8_b503_fb1ef3651ec0__

#include "FieldBase.h"


namespace Wtx {
  namespace Dbo {

template <typename T> class FieldWeak
: public FieldBase
{
  public:

    FieldWeak()
    {
    }

    const T & data() const
    {
      return m_data;
    }

    void setData( const T & value )
    {
      m_data = value;
    }

    const T & value() const
    {
      return m_data;
    }

    void setValue( const T & value )
    {
      m_data = value;
    }

    void setValue( const std::string & value, Wtx::Dbo::Session * s )
    {
      std::cout << __FILE__ << ":" << __LINE__ << std::endl;
    }

    template <class Action> void persist( Action & a, FieldDefBase * fieldDef )
    {
      if( !fieldDef )
        std::cout << __FILE__ << ":" << __LINE__ << "no field def" << std::endl;

      else
        Wt::Dbo::hasOne( a, m_data, fieldDef-> fieldName() );
    }

//  protected:

      static Wtx::Dbo::FieldDefBase * s_fieldDef;
      T m_data;

  private:

}; //  endtemplate <typename T> class FieldWeak

  } // endnamespace Dbo
} // endnamespace Wtx

#include "FieldWeak_imp.h"

#endif


