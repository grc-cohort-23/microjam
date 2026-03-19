#include "jas/jas_stars.h"

#include <bn_regular_bg_ptr.h>

#include "bn_regular_bg_items_jas_stars_background.h"

// All game functions/classes/variables/constants scoped to the namespace
namespace jas
{

  /**
   * Stars constructor
   *
   * @param position The location to put the stars
   */
  stars::stars() : // Use regular_bg_items and create_bg
     _bg_stars(bn::regular_bg_items::jas_stars_background.create_bg(STARS_POSITION))
  {
    // Backgrounds use set_priority instead of set_z_order
    _bg_stars.set_priority(3);
    _bg_stars.set_visible(true);
  }

  void stars::set_visibility(bool setting)
  {
    _bg_stars.set_visible(setting);
  }
}