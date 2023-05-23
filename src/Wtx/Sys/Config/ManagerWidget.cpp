
#include <Wt/WText.h>
#include <Wt/WHBoxLayout.h>

#include <Wtx/Sys/Session.h>
#include <Wtx/Dbo/TableViewManager.h>
#include <Wtx/Dbo/TemplateFormView.h>
#include <Wtx/Dbo/DetailForm.h>

#include "Item.h"
#include "ManagerWidget.h"


class ConfigDetail
: public Wtx::Dbo::DetailForm<Wtx::Sys::Config::Item>
{
  public:

    ConfigDetail( Wt::Dbo::ptr<Wtx::Sys::Config::Item> & item )
    : Wtx::Dbo::DetailForm<Wtx::Sys::Config::Item>
      (
        "sysConfig.detailForm",
        item
      )
    {
    }

};



Wtx::Sys::Config::ManagerWidget::ManagerWidget( Wtx::Sys::Session * session )
{

  auto layout = std::make_unique<Wt::WHBoxLayout>();

  {
    Wtx::TableViewDef::ViewDef viewDef =
    {
      /* title                */ "Config",
      /* tip                  */ "",
      /* headerCount          */ 0,
      /* selectionMode        */ Wt::SelectionMode::Single,
      /* columnResizeEnabled  */ true,
      /* alternatingRowColors */ true,
      /* sql                  */ "",
      /* filter               */ "",
      /* subFilter            */ "",
      /* idin                 */ {},
      /* doubleClick          */ 0,
      /* showHeader           */ true,
      /* showFooter           */ true,
      /* showPrevNext         */ false,
      /* hideSearch           */ true,
      /* allowFilter          */ false,
      /* allowAdd             */ true,
      /* allowChange          */ true,
      /* allowDelete          */ false,
      /* allowExport          */ true,
      /* allowSearch          */ true,
      /* allowPrint           */ false,
      /* allowUnlock          */ false,
      /* additional           */ "",
      /* itemDelegate         */ nullptr,


      /* sortFields           */
      {
        "id"
      },

      /* search fields        */
      {
      },

      /* column defs          */
      {
        { "id",           "",  50, Wt::AlignmentFlag::Left, "", nullptr  },
        { "isActive",     "",  75, Wt::AlignmentFlag::Left, "", nullptr  },
        { "keyField",     "", 350, Wt::AlignmentFlag::Left, "", nullptr  },
        { "cfyField",     "", 350, Wt::AlignmentFlag::Left, "", nullptr  },
        { "tag",          "", 150, Wt::AlignmentFlag::Left, "", nullptr  },
      },

      /* column names         */
      {
        "id",
        "version"
      }
    };

    layout-> addWidget( std::make_unique< Wtx::Dbo::TableViewManager< Wtx::Sys::Config::Item, ConfigDetail > >( viewDef, session ) );

  }

  setLayout( std::move(layout) );

} // endWtx::Sys::Config::ManagerWidget::ManagerWidget()





