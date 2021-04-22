/*
    src/example_icons.cpp -- C++ version of an example application that shows
    all available Entypo icons as they would appear in NanoGUI itself.  For a Python
    implementation, see '../python/example_icons.py'.

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

/* Developer note: need to make a change to this file?
 * Please raise an Issue on GitHub describing what needs to change.  This file
 * was generated, so the scripts that generated it needs to update as well.
 */

#include <nanogui/nanogui.h>
using namespace nanogui;

// add a button to the wrapper with a fixed size
// `icon` should be the defined constant in nanogui/entypo.h
// the button label will be the string that represents this
#define ADD_BUTTON(icon)                                   \
    auto b_##icon = new Button(wrapper, #icon, icon);      \
    b_##icon->set_icon_position(Button::IconPosition::Left); \
    b_##icon->set_fixed_width(half_width);

int main(int /* argc */, char ** /* argv */) {
    nanogui::init();

    /* scoped variables */ {
        static constexpr int width      = 1000;
        static constexpr int half_width = width / 2;
        static constexpr int height     = 800;

        // create a fixed size screen with one window
        Screen *screen = new Screen({width, height}, "NanoGUI Icons", false);
        Window *window = new Window(screen, "All Icons");
        window->set_position({0, 0});
        window->set_fixed_size({width, height});

        // attach a vertical scroll panel
        auto vscroll = new VScrollPanel(window);
        vscroll->set_fixed_size({width, height});

        // vscroll should only have *ONE* child. this is what `wrapper` is for
        auto wrapper = new Widget(vscroll);
        wrapper->set_fixed_size({width, height});
        wrapper->set_layout(new GridLayout());// defaults: 2 columns

        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        ADD_BUTTON(FA_AD);
        ADD_BUTTON(FA_ADDRESS_BOOK);
        ADD_BUTTON(FA_ADDRESS_CARD);
        ADD_BUTTON(FA_ADJUST);
        ADD_BUTTON(FA_AIR_FRESHENER);
        ADD_BUTTON(FA_ALIGN_CENTER);
        ADD_BUTTON(FA_ALIGN_JUSTIFY);
        ADD_BUTTON(FA_ALIGN_LEFT);
        ADD_BUTTON(FA_ALIGN_RIGHT);
        ADD_BUTTON(FA_ALLERGIES);
        ADD_BUTTON(FA_AMBULANCE);
        ADD_BUTTON(FA_AMERICAN_SIGN_LANGUAGE_INTERPRETING);
        ADD_BUTTON(FA_ANCHOR);
        ADD_BUTTON(FA_ANGLE_DOUBLE_DOWN);
        ADD_BUTTON(FA_ANGLE_DOUBLE_LEFT);
        ADD_BUTTON(FA_ANGLE_DOUBLE_RIGHT);
        ADD_BUTTON(FA_ANGLE_DOUBLE_UP);
        ADD_BUTTON(FA_ANGLE_DOWN);
        ADD_BUTTON(FA_ANGLE_LEFT);
        ADD_BUTTON(FA_ANGLE_RIGHT);
        ADD_BUTTON(FA_ANGLE_UP);
        ADD_BUTTON(FA_ANGRY);
        ADD_BUTTON(FA_ANKH);
        ADD_BUTTON(FA_APPLE_ALT);
        ADD_BUTTON(FA_ARCHIVE);
        ADD_BUTTON(FA_ARCHWAY);
        ADD_BUTTON(FA_ARROW_ALT_CIRCLE_DOWN);
        ADD_BUTTON(FA_ARROW_ALT_CIRCLE_LEFT);
        ADD_BUTTON(FA_ARROW_ALT_CIRCLE_RIGHT);
        ADD_BUTTON(FA_ARROW_ALT_CIRCLE_UP);
        ADD_BUTTON(FA_ARROW_CIRCLE_DOWN);
        ADD_BUTTON(FA_ARROW_CIRCLE_LEFT);
        ADD_BUTTON(FA_ARROW_CIRCLE_RIGHT);
        ADD_BUTTON(FA_ARROW_CIRCLE_UP);
        ADD_BUTTON(FA_ARROW_DOWN);
        ADD_BUTTON(FA_ARROW_LEFT);
        ADD_BUTTON(FA_ARROW_RIGHT);
        ADD_BUTTON(FA_ARROW_UP);
        ADD_BUTTON(FA_ARROWS_ALT);
        ADD_BUTTON(FA_ARROWS_ALT_H);
        ADD_BUTTON(FA_ARROWS_ALT_V);
        ADD_BUTTON(FA_ASSISTIVE_LISTENING_SYSTEMS);
        ADD_BUTTON(FA_ASTERISK);
        ADD_BUTTON(FA_AT);
        ADD_BUTTON(FA_ATLAS);
        ADD_BUTTON(FA_ATOM);
        ADD_BUTTON(FA_AUDIO_DESCRIPTION);
        ADD_BUTTON(FA_AWARD);
        ADD_BUTTON(FA_BABY);
        ADD_BUTTON(FA_BABY_CARRIAGE);
        ADD_BUTTON(FA_BACKSPACE);
        ADD_BUTTON(FA_BACKWARD);
        ADD_BUTTON(FA_BACON);
        ADD_BUTTON(FA_BALANCE_SCALE);
        ADD_BUTTON(FA_BALANCE_SCALE_LEFT);
        ADD_BUTTON(FA_BALANCE_SCALE_RIGHT);
        ADD_BUTTON(FA_BAN);
        ADD_BUTTON(FA_BAND_AID);
        ADD_BUTTON(FA_BARCODE);
        ADD_BUTTON(FA_BARS);
        ADD_BUTTON(FA_BASEBALL_BALL);
        ADD_BUTTON(FA_BASKETBALL_BALL);
        ADD_BUTTON(FA_BATH);
        ADD_BUTTON(FA_BATTERY_EMPTY);
        ADD_BUTTON(FA_BATTERY_FULL);
        ADD_BUTTON(FA_BATTERY_HALF);
        ADD_BUTTON(FA_BATTERY_QUARTER);
        ADD_BUTTON(FA_BATTERY_THREE_QUARTERS);
        ADD_BUTTON(FA_BED);
        ADD_BUTTON(FA_BEER);
        ADD_BUTTON(FA_BELL);
        ADD_BUTTON(FA_BELL_SLASH);
        ADD_BUTTON(FA_BEZIER_CURVE);
        ADD_BUTTON(FA_BIBLE);
        ADD_BUTTON(FA_BICYCLE);
        ADD_BUTTON(FA_BIKING);
        ADD_BUTTON(FA_BINOCULARS);
        ADD_BUTTON(FA_BIOHAZARD);
        ADD_BUTTON(FA_BIRTHDAY_CAKE);
        ADD_BUTTON(FA_BLENDER);
        ADD_BUTTON(FA_BLENDER_PHONE);
        ADD_BUTTON(FA_BLIND);
        ADD_BUTTON(FA_BLOG);
        ADD_BUTTON(FA_BOLD);
        ADD_BUTTON(FA_BOLT);
        ADD_BUTTON(FA_BOMB);
        ADD_BUTTON(FA_BONE);
        ADD_BUTTON(FA_BONG);
        ADD_BUTTON(FA_BOOK);
        ADD_BUTTON(FA_BOOK_DEAD);
        ADD_BUTTON(FA_BOOK_MEDICAL);
        ADD_BUTTON(FA_BOOK_OPEN);
        ADD_BUTTON(FA_BOOK_READER);
        ADD_BUTTON(FA_BOOKMARK);
        ADD_BUTTON(FA_BORDER_ALL);
        ADD_BUTTON(FA_BORDER_NONE);
        ADD_BUTTON(FA_BORDER_STYLE);
        ADD_BUTTON(FA_BOWLING_BALL);
        ADD_BUTTON(FA_BOX);
        ADD_BUTTON(FA_BOX_OPEN);
        ADD_BUTTON(FA_BOXES);
        ADD_BUTTON(FA_BRAILLE);
        ADD_BUTTON(FA_BRAIN);
        ADD_BUTTON(FA_BREAD_SLICE);
        ADD_BUTTON(FA_BRIEFCASE);
        ADD_BUTTON(FA_BRIEFCASE_MEDICAL);
        ADD_BUTTON(FA_BROADCAST_TOWER);
        ADD_BUTTON(FA_BROOM);
        ADD_BUTTON(FA_BRUSH);
        ADD_BUTTON(FA_BUG);
        ADD_BUTTON(FA_BUILDING);
        ADD_BUTTON(FA_BULLHORN);
        ADD_BUTTON(FA_BULLSEYE);
        ADD_BUTTON(FA_BURN);
        ADD_BUTTON(FA_BUS);
        ADD_BUTTON(FA_BUS_ALT);
        ADD_BUTTON(FA_BUSINESS_TIME);
        ADD_BUTTON(FA_CALCULATOR);
        ADD_BUTTON(FA_CALENDAR);
        ADD_BUTTON(FA_CALENDAR_ALT);
        ADD_BUTTON(FA_CALENDAR_CHECK);
        ADD_BUTTON(FA_CALENDAR_DAY);
        ADD_BUTTON(FA_CALENDAR_MINUS);
        ADD_BUTTON(FA_CALENDAR_PLUS);
        ADD_BUTTON(FA_CALENDAR_TIMES);
        ADD_BUTTON(FA_CALENDAR_WEEK);
        ADD_BUTTON(FA_CAMERA);
        ADD_BUTTON(FA_CAMERA_RETRO);
        ADD_BUTTON(FA_CAMPGROUND);
        ADD_BUTTON(FA_CANDY_CANE);
        ADD_BUTTON(FA_CANNABIS);
        ADD_BUTTON(FA_CAPSULES);
        ADD_BUTTON(FA_CAR);
        ADD_BUTTON(FA_CAR_ALT);
        ADD_BUTTON(FA_CAR_BATTERY);
        ADD_BUTTON(FA_CAR_CRASH);
        ADD_BUTTON(FA_CAR_SIDE);
        ADD_BUTTON(FA_CARET_DOWN);
        ADD_BUTTON(FA_CARET_LEFT);
        ADD_BUTTON(FA_CARET_RIGHT);
        ADD_BUTTON(FA_CARET_SQUARE_DOWN);
        ADD_BUTTON(FA_CARET_SQUARE_LEFT);
        ADD_BUTTON(FA_CARET_SQUARE_RIGHT);
        ADD_BUTTON(FA_CARET_SQUARE_UP);
        ADD_BUTTON(FA_CARET_UP);
        ADD_BUTTON(FA_CARROT);
        ADD_BUTTON(FA_CART_ARROW_DOWN);
        ADD_BUTTON(FA_CART_PLUS);
        ADD_BUTTON(FA_CASH_REGISTER);
        ADD_BUTTON(FA_CAT);
        ADD_BUTTON(FA_CERTIFICATE);
        ADD_BUTTON(FA_CHAIR);
        ADD_BUTTON(FA_CHALKBOARD);
        ADD_BUTTON(FA_CHALKBOARD_TEACHER);
        ADD_BUTTON(FA_CHARGING_STATION);
        ADD_BUTTON(FA_CHART_AREA);
        ADD_BUTTON(FA_CHART_BAR);
        ADD_BUTTON(FA_CHART_LINE);
        ADD_BUTTON(FA_CHART_PIE);
        ADD_BUTTON(FA_CHECK);
        ADD_BUTTON(FA_CHECK_CIRCLE);
        ADD_BUTTON(FA_CHECK_DOUBLE);
        ADD_BUTTON(FA_CHECK_SQUARE);
        ADD_BUTTON(FA_CHEESE);
        ADD_BUTTON(FA_CHESS);
        ADD_BUTTON(FA_CHESS_BISHOP);
        ADD_BUTTON(FA_CHESS_BOARD);
        ADD_BUTTON(FA_CHESS_KING);
        ADD_BUTTON(FA_CHESS_KNIGHT);
        ADD_BUTTON(FA_CHESS_PAWN);
        ADD_BUTTON(FA_CHESS_QUEEN);
        ADD_BUTTON(FA_CHESS_ROOK);
        ADD_BUTTON(FA_CHEVRON_CIRCLE_DOWN);
        ADD_BUTTON(FA_CHEVRON_CIRCLE_LEFT);
        ADD_BUTTON(FA_CHEVRON_CIRCLE_RIGHT);
        ADD_BUTTON(FA_CHEVRON_CIRCLE_UP);
        ADD_BUTTON(FA_CHEVRON_DOWN);
        ADD_BUTTON(FA_CHEVRON_LEFT);
        ADD_BUTTON(FA_CHEVRON_RIGHT);
        ADD_BUTTON(FA_CHEVRON_UP);
        ADD_BUTTON(FA_CHILD);
        ADD_BUTTON(FA_CHURCH);
        ADD_BUTTON(FA_CIRCLE);
        ADD_BUTTON(FA_CIRCLE_NOTCH);
        ADD_BUTTON(FA_CITY);
        ADD_BUTTON(FA_CLINIC_MEDICAL);
        ADD_BUTTON(FA_CLIPBOARD);
        ADD_BUTTON(FA_CLIPBOARD_CHECK);
        ADD_BUTTON(FA_CLIPBOARD_LIST);
        ADD_BUTTON(FA_CLOCK);
        ADD_BUTTON(FA_CLONE);
        ADD_BUTTON(FA_CLOSED_CAPTIONING);
        ADD_BUTTON(FA_CLOUD);
        ADD_BUTTON(FA_CLOUD_DOWNLOAD_ALT);
        ADD_BUTTON(FA_CLOUD_MEATBALL);
        ADD_BUTTON(FA_CLOUD_MOON);
        ADD_BUTTON(FA_CLOUD_MOON_RAIN);
        ADD_BUTTON(FA_CLOUD_RAIN);
        ADD_BUTTON(FA_CLOUD_SHOWERS_HEAVY);
        ADD_BUTTON(FA_CLOUD_SUN);
        ADD_BUTTON(FA_CLOUD_SUN_RAIN);
        ADD_BUTTON(FA_CLOUD_UPLOAD_ALT);
        ADD_BUTTON(FA_COCKTAIL);
        ADD_BUTTON(FA_CODE);
        ADD_BUTTON(FA_CODE_BRANCH);
        ADD_BUTTON(FA_COFFEE);
        ADD_BUTTON(FA_COG);
        ADD_BUTTON(FA_COGS);
        ADD_BUTTON(FA_COINS);
        ADD_BUTTON(FA_COLUMNS);
        ADD_BUTTON(FA_COMMENT);
        ADD_BUTTON(FA_COMMENT_ALT);
        ADD_BUTTON(FA_COMMENT_DOLLAR);
        ADD_BUTTON(FA_COMMENT_DOTS);
        ADD_BUTTON(FA_COMMENT_MEDICAL);
        ADD_BUTTON(FA_COMMENT_SLASH);
        ADD_BUTTON(FA_COMMENTS);
        ADD_BUTTON(FA_COMMENTS_DOLLAR);
        ADD_BUTTON(FA_COMPACT_DISC);
        ADD_BUTTON(FA_COMPASS);
        ADD_BUTTON(FA_COMPRESS);
        ADD_BUTTON(FA_COMPRESS_ARROWS_ALT);
        ADD_BUTTON(FA_CONCIERGE_BELL);
        ADD_BUTTON(FA_COOKIE);
        ADD_BUTTON(FA_COOKIE_BITE);
        ADD_BUTTON(FA_COPY);
        ADD_BUTTON(FA_COPYRIGHT);
        ADD_BUTTON(FA_COUCH);
        ADD_BUTTON(FA_CREDIT_CARD);
        ADD_BUTTON(FA_CROP);
        ADD_BUTTON(FA_CROP_ALT);
        ADD_BUTTON(FA_CROSS);
        ADD_BUTTON(FA_CROSSHAIRS);
        ADD_BUTTON(FA_CROW);
        ADD_BUTTON(FA_CROWN);
        ADD_BUTTON(FA_CRUTCH);
        ADD_BUTTON(FA_CUBE);
        ADD_BUTTON(FA_CUBES);
        ADD_BUTTON(FA_CUT);
        ADD_BUTTON(FA_DATABASE);
        ADD_BUTTON(FA_DEAF);
        ADD_BUTTON(FA_DEMOCRAT);
        ADD_BUTTON(FA_DESKTOP);
        ADD_BUTTON(FA_DHARMACHAKRA);
        ADD_BUTTON(FA_DIAGNOSES);
        ADD_BUTTON(FA_DICE);
        ADD_BUTTON(FA_DICE_D20);
        ADD_BUTTON(FA_DICE_D6);
        ADD_BUTTON(FA_DICE_FIVE);
        ADD_BUTTON(FA_DICE_FOUR);
        ADD_BUTTON(FA_DICE_ONE);
        ADD_BUTTON(FA_DICE_SIX);
        ADD_BUTTON(FA_DICE_THREE);
        ADD_BUTTON(FA_DICE_TWO);
        ADD_BUTTON(FA_DIGITAL_TACHOGRAPH);
        ADD_BUTTON(FA_DIRECTIONS);
        ADD_BUTTON(FA_DIVIDE);
        ADD_BUTTON(FA_DIZZY);
        ADD_BUTTON(FA_DNA);
        ADD_BUTTON(FA_DOG);
        ADD_BUTTON(FA_DOLLAR_SIGN);
        ADD_BUTTON(FA_DOLLY);
        ADD_BUTTON(FA_DOLLY_FLATBED);
        ADD_BUTTON(FA_DONATE);
        ADD_BUTTON(FA_DOOR_CLOSED);
        ADD_BUTTON(FA_DOOR_OPEN);
        ADD_BUTTON(FA_DOT_CIRCLE);
        ADD_BUTTON(FA_DOVE);
        ADD_BUTTON(FA_DOWNLOAD);
        ADD_BUTTON(FA_DRAFTING_COMPASS);
        ADD_BUTTON(FA_DRAGON);
        ADD_BUTTON(FA_DRAW_POLYGON);
        ADD_BUTTON(FA_DRUM);
        ADD_BUTTON(FA_DRUM_STEELPAN);
        ADD_BUTTON(FA_DRUMSTICK_BITE);
        ADD_BUTTON(FA_DUMBBELL);
        ADD_BUTTON(FA_DUMPSTER);
        ADD_BUTTON(FA_DUMPSTER_FIRE);
        ADD_BUTTON(FA_DUNGEON);
        ADD_BUTTON(FA_EDIT);
        ADD_BUTTON(FA_EGG);
        ADD_BUTTON(FA_EJECT);
        ADD_BUTTON(FA_ELLIPSIS_H);
        ADD_BUTTON(FA_ELLIPSIS_V);
        ADD_BUTTON(FA_ENVELOPE);
        ADD_BUTTON(FA_ENVELOPE_OPEN);
        ADD_BUTTON(FA_ENVELOPE_OPEN_TEXT);
        ADD_BUTTON(FA_ENVELOPE_SQUARE);
        ADD_BUTTON(FA_EQUALS);
        ADD_BUTTON(FA_ERASER);
        ADD_BUTTON(FA_ETHERNET);
        ADD_BUTTON(FA_EURO_SIGN);
        ADD_BUTTON(FA_EXCHANGE_ALT);
        ADD_BUTTON(FA_EXCLAMATION);
        ADD_BUTTON(FA_EXCLAMATION_CIRCLE);
        ADD_BUTTON(FA_EXCLAMATION_TRIANGLE);
        ADD_BUTTON(FA_EXPAND);
        ADD_BUTTON(FA_EXPAND_ARROWS_ALT);
        ADD_BUTTON(FA_EXTERNAL_LINK_ALT);
        ADD_BUTTON(FA_EXTERNAL_LINK_SQUARE_ALT);
        ADD_BUTTON(FA_EYE);
        ADD_BUTTON(FA_EYE_DROPPER);
        ADD_BUTTON(FA_EYE_SLASH);
        ADD_BUTTON(FA_FAN);
        ADD_BUTTON(FA_FAST_BACKWARD);
        ADD_BUTTON(FA_FAST_FORWARD);
        ADD_BUTTON(FA_FAX);
        ADD_BUTTON(FA_FEATHER);
        ADD_BUTTON(FA_FEATHER_ALT);
        ADD_BUTTON(FA_FEMALE);
        ADD_BUTTON(FA_FIGHTER_JET);
        ADD_BUTTON(FA_FILE);
        ADD_BUTTON(FA_FILE_ALT);
        ADD_BUTTON(FA_FILE_ARCHIVE);
        ADD_BUTTON(FA_FILE_AUDIO);
        ADD_BUTTON(FA_FILE_CODE);
        ADD_BUTTON(FA_FILE_CONTRACT);
        ADD_BUTTON(FA_FILE_CSV);
        ADD_BUTTON(FA_FILE_DOWNLOAD);
        ADD_BUTTON(FA_FILE_EXCEL);
        ADD_BUTTON(FA_FILE_EXPORT);
        ADD_BUTTON(FA_FILE_IMAGE);
        ADD_BUTTON(FA_FILE_IMPORT);
        ADD_BUTTON(FA_FILE_INVOICE);
        ADD_BUTTON(FA_FILE_INVOICE_DOLLAR);
        ADD_BUTTON(FA_FILE_MEDICAL);
        ADD_BUTTON(FA_FILE_MEDICAL_ALT);
        ADD_BUTTON(FA_FILE_PDF);
        ADD_BUTTON(FA_FILE_POWERPOINT);
        ADD_BUTTON(FA_FILE_PRESCRIPTION);
        ADD_BUTTON(FA_FILE_SIGNATURE);
        ADD_BUTTON(FA_FILE_UPLOAD);
        ADD_BUTTON(FA_FILE_VIDEO);
        ADD_BUTTON(FA_FILE_WORD);
        ADD_BUTTON(FA_FILL);
        ADD_BUTTON(FA_FILL_DRIP);
        ADD_BUTTON(FA_FILM);
        ADD_BUTTON(FA_FILTER);
        ADD_BUTTON(FA_FINGERPRINT);
        ADD_BUTTON(FA_FIRE);
        ADD_BUTTON(FA_FIRE_ALT);
        ADD_BUTTON(FA_FIRE_EXTINGUISHER);
        ADD_BUTTON(FA_FIRST_AID);
        ADD_BUTTON(FA_FISH);
        ADD_BUTTON(FA_FIST_RAISED);
        ADD_BUTTON(FA_FLAG);
        ADD_BUTTON(FA_FLAG_CHECKERED);
        ADD_BUTTON(FA_FLAG_USA);
        ADD_BUTTON(FA_FLASK);
        ADD_BUTTON(FA_FLUSHED);
        ADD_BUTTON(FA_FOLDER);
        ADD_BUTTON(FA_FOLDER_MINUS);
        ADD_BUTTON(FA_FOLDER_OPEN);
        ADD_BUTTON(FA_FOLDER_PLUS);
        ADD_BUTTON(FA_FONT);
        ADD_BUTTON(FA_FONT_AWESOME_LOGO_FULL);
        ADD_BUTTON(FA_FOOTBALL_BALL);
        ADD_BUTTON(FA_FORWARD);
        ADD_BUTTON(FA_FROG);
        ADD_BUTTON(FA_FROWN);
        ADD_BUTTON(FA_FROWN_OPEN);
        ADD_BUTTON(FA_FUNNEL_DOLLAR);
        ADD_BUTTON(FA_FUTBOL);
        ADD_BUTTON(FA_GAMEPAD);
        ADD_BUTTON(FA_GAS_PUMP);
        ADD_BUTTON(FA_GAVEL);
        ADD_BUTTON(FA_GEM);
        ADD_BUTTON(FA_GENDERLESS);
        ADD_BUTTON(FA_GHOST);
        ADD_BUTTON(FA_GIFT);
        ADD_BUTTON(FA_GIFTS);
        ADD_BUTTON(FA_GLASS_CHEERS);
        ADD_BUTTON(FA_GLASS_MARTINI);
        ADD_BUTTON(FA_GLASS_MARTINI_ALT);
        ADD_BUTTON(FA_GLASS_WHISKEY);
        ADD_BUTTON(FA_GLASSES);
        ADD_BUTTON(FA_GLOBE);
        ADD_BUTTON(FA_GLOBE_AFRICA);
        ADD_BUTTON(FA_GLOBE_AMERICAS);
        ADD_BUTTON(FA_GLOBE_ASIA);
        ADD_BUTTON(FA_GLOBE_EUROPE);
        ADD_BUTTON(FA_GOLF_BALL);
        ADD_BUTTON(FA_GOPURAM);
        ADD_BUTTON(FA_GRADUATION_CAP);
        ADD_BUTTON(FA_GREATER_THAN);
        ADD_BUTTON(FA_GREATER_THAN_EQUAL);
        ADD_BUTTON(FA_GRIMACE);
        ADD_BUTTON(FA_GRIN);
        ADD_BUTTON(FA_GRIN_ALT);
        ADD_BUTTON(FA_GRIN_BEAM);
        ADD_BUTTON(FA_GRIN_BEAM_SWEAT);
        ADD_BUTTON(FA_GRIN_HEARTS);
        ADD_BUTTON(FA_GRIN_SQUINT);
        ADD_BUTTON(FA_GRIN_SQUINT_TEARS);
        ADD_BUTTON(FA_GRIN_STARS);
        ADD_BUTTON(FA_GRIN_TEARS);
        ADD_BUTTON(FA_GRIN_TONGUE);
        ADD_BUTTON(FA_GRIN_TONGUE_SQUINT);
        ADD_BUTTON(FA_GRIN_TONGUE_WINK);
        ADD_BUTTON(FA_GRIN_WINK);
        ADD_BUTTON(FA_GRIP_HORIZONTAL);
        ADD_BUTTON(FA_GRIP_LINES);
        ADD_BUTTON(FA_GRIP_LINES_VERTICAL);
        ADD_BUTTON(FA_GRIP_VERTICAL);
        ADD_BUTTON(FA_GUITAR);
        ADD_BUTTON(FA_H_SQUARE);
        ADD_BUTTON(FA_HAMBURGER);
        ADD_BUTTON(FA_HAMMER);
        ADD_BUTTON(FA_HAMSA);
        ADD_BUTTON(FA_HAND_HOLDING);
        ADD_BUTTON(FA_HAND_HOLDING_HEART);
        ADD_BUTTON(FA_HAND_HOLDING_USD);
        ADD_BUTTON(FA_HAND_LIZARD);
        ADD_BUTTON(FA_HAND_MIDDLE_FINGER);
        ADD_BUTTON(FA_HAND_PAPER);
        ADD_BUTTON(FA_HAND_PEACE);
        ADD_BUTTON(FA_HAND_POINT_DOWN);
        ADD_BUTTON(FA_HAND_POINT_LEFT);
        ADD_BUTTON(FA_HAND_POINT_RIGHT);
        ADD_BUTTON(FA_HAND_POINT_UP);
        ADD_BUTTON(FA_HAND_POINTER);
        ADD_BUTTON(FA_HAND_ROCK);
        ADD_BUTTON(FA_HAND_SCISSORS);
        ADD_BUTTON(FA_HAND_SPOCK);
        ADD_BUTTON(FA_HANDS);
        ADD_BUTTON(FA_HANDS_HELPING);
        ADD_BUTTON(FA_HANDSHAKE);
        ADD_BUTTON(FA_HANUKIAH);
        ADD_BUTTON(FA_HARD_HAT);
        ADD_BUTTON(FA_HASHTAG);
        ADD_BUTTON(FA_HAT_WIZARD);
        ADD_BUTTON(FA_HAYKAL);
        ADD_BUTTON(FA_HDD);
        ADD_BUTTON(FA_HEADING);
        ADD_BUTTON(FA_HEADPHONES);
        ADD_BUTTON(FA_HEADPHONES_ALT);
        ADD_BUTTON(FA_HEADSET);
        ADD_BUTTON(FA_HEART);
        ADD_BUTTON(FA_HEART_BROKEN);
        ADD_BUTTON(FA_HEARTBEAT);
        ADD_BUTTON(FA_HELICOPTER);
        ADD_BUTTON(FA_HIGHLIGHTER);
        ADD_BUTTON(FA_HIKING);
        ADD_BUTTON(FA_HIPPO);
        ADD_BUTTON(FA_HISTORY);
        ADD_BUTTON(FA_HOCKEY_PUCK);
        ADD_BUTTON(FA_HOLLY_BERRY);
        ADD_BUTTON(FA_HOME);
        ADD_BUTTON(FA_HORSE);
        ADD_BUTTON(FA_HORSE_HEAD);
        ADD_BUTTON(FA_HOSPITAL);
        ADD_BUTTON(FA_HOSPITAL_ALT);
        ADD_BUTTON(FA_HOSPITAL_SYMBOL);
        ADD_BUTTON(FA_HOT_TUB);
        ADD_BUTTON(FA_HOTDOG);
        ADD_BUTTON(FA_HOTEL);
        ADD_BUTTON(FA_HOURGLASS);
        ADD_BUTTON(FA_HOURGLASS_END);
        ADD_BUTTON(FA_HOURGLASS_HALF);
        ADD_BUTTON(FA_HOURGLASS_START);
        ADD_BUTTON(FA_HOUSE_DAMAGE);
        ADD_BUTTON(FA_HRYVNIA);
        ADD_BUTTON(FA_I_CURSOR);
        ADD_BUTTON(FA_ICE_CREAM);
        ADD_BUTTON(FA_ICICLES);
        ADD_BUTTON(FA_ICONS);
        ADD_BUTTON(FA_ID_BADGE);
        ADD_BUTTON(FA_ID_CARD);
        ADD_BUTTON(FA_ID_CARD_ALT);
        ADD_BUTTON(FA_IGLOO);
        ADD_BUTTON(FA_IMAGE);
        ADD_BUTTON(FA_IMAGES);
        ADD_BUTTON(FA_INBOX);
        ADD_BUTTON(FA_INDENT);
        ADD_BUTTON(FA_INDUSTRY);
        ADD_BUTTON(FA_INFINITY);
        ADD_BUTTON(FA_INFO);
        ADD_BUTTON(FA_INFO_CIRCLE);
        ADD_BUTTON(FA_ITALIC);
        ADD_BUTTON(FA_JEDI);
        ADD_BUTTON(FA_JOINT);
        ADD_BUTTON(FA_JOURNAL_WHILLS);
        ADD_BUTTON(FA_KAABA);
        ADD_BUTTON(FA_KEY);
        ADD_BUTTON(FA_KEYBOARD);
        ADD_BUTTON(FA_KHANDA);
        ADD_BUTTON(FA_KISS);
        ADD_BUTTON(FA_KISS_BEAM);
        ADD_BUTTON(FA_KISS_WINK_HEART);
        ADD_BUTTON(FA_KIWI_BIRD);
        ADD_BUTTON(FA_LANDMARK);
        ADD_BUTTON(FA_LANGUAGE);
        ADD_BUTTON(FA_LAPTOP);
        ADD_BUTTON(FA_LAPTOP_CODE);
        ADD_BUTTON(FA_LAPTOP_MEDICAL);
        ADD_BUTTON(FA_LAUGH);
        ADD_BUTTON(FA_LAUGH_BEAM);
        ADD_BUTTON(FA_LAUGH_SQUINT);
        ADD_BUTTON(FA_LAUGH_WINK);
        ADD_BUTTON(FA_LAYER_GROUP);
        ADD_BUTTON(FA_LEAF);
        ADD_BUTTON(FA_LEMON);
        ADD_BUTTON(FA_LESS_THAN);
        ADD_BUTTON(FA_LESS_THAN_EQUAL);
        ADD_BUTTON(FA_LEVEL_DOWN_ALT);
        ADD_BUTTON(FA_LEVEL_UP_ALT);
        ADD_BUTTON(FA_LIFE_RING);
        ADD_BUTTON(FA_LIGHTBULB);
        ADD_BUTTON(FA_LINK);
        ADD_BUTTON(FA_LIRA_SIGN);
        ADD_BUTTON(FA_LIST);
        ADD_BUTTON(FA_LIST_ALT);
        ADD_BUTTON(FA_LIST_OL);
        ADD_BUTTON(FA_LIST_UL);
        ADD_BUTTON(FA_LOCATION_ARROW);
        ADD_BUTTON(FA_LOCK);
        ADD_BUTTON(FA_LOCK_OPEN);
        ADD_BUTTON(FA_LONG_ARROW_ALT_DOWN);
        ADD_BUTTON(FA_LONG_ARROW_ALT_LEFT);
        ADD_BUTTON(FA_LONG_ARROW_ALT_RIGHT);
        ADD_BUTTON(FA_LONG_ARROW_ALT_UP);
        ADD_BUTTON(FA_LOW_VISION);
        ADD_BUTTON(FA_LUGGAGE_CART);
        ADD_BUTTON(FA_MAGIC);
        ADD_BUTTON(FA_MAGNET);
        ADD_BUTTON(FA_MAIL_BULK);
        ADD_BUTTON(FA_MALE);
        ADD_BUTTON(FA_MAP);
        ADD_BUTTON(FA_MAP_MARKED);
        ADD_BUTTON(FA_MAP_MARKED_ALT);
        ADD_BUTTON(FA_MAP_MARKER);
        ADD_BUTTON(FA_MAP_MARKER_ALT);
        ADD_BUTTON(FA_MAP_PIN);
        ADD_BUTTON(FA_MAP_SIGNS);
        ADD_BUTTON(FA_MARKER);
        ADD_BUTTON(FA_MARS);
        ADD_BUTTON(FA_MARS_DOUBLE);
        ADD_BUTTON(FA_MARS_STROKE);
        ADD_BUTTON(FA_MARS_STROKE_H);
        ADD_BUTTON(FA_MARS_STROKE_V);
        ADD_BUTTON(FA_MASK);
        ADD_BUTTON(FA_MEDAL);
        ADD_BUTTON(FA_MEDKIT);
        ADD_BUTTON(FA_MEH);
        ADD_BUTTON(FA_MEH_BLANK);
        ADD_BUTTON(FA_MEH_ROLLING_EYES);
        ADD_BUTTON(FA_MEMORY);
        ADD_BUTTON(FA_MENORAH);
        ADD_BUTTON(FA_MERCURY);
        ADD_BUTTON(FA_METEOR);
        ADD_BUTTON(FA_MICROCHIP);
        ADD_BUTTON(FA_MICROPHONE);
        ADD_BUTTON(FA_MICROPHONE_ALT);
        ADD_BUTTON(FA_MICROPHONE_ALT_SLASH);
        ADD_BUTTON(FA_MICROPHONE_SLASH);
        ADD_BUTTON(FA_MICROSCOPE);
        ADD_BUTTON(FA_MINUS);
        ADD_BUTTON(FA_MINUS_CIRCLE);
        ADD_BUTTON(FA_MINUS_SQUARE);
        ADD_BUTTON(FA_MITTEN);
        ADD_BUTTON(FA_MOBILE);
        ADD_BUTTON(FA_MOBILE_ALT);
        ADD_BUTTON(FA_MONEY_BILL);
        ADD_BUTTON(FA_MONEY_BILL_ALT);
        ADD_BUTTON(FA_MONEY_BILL_WAVE);
        ADD_BUTTON(FA_MONEY_BILL_WAVE_ALT);
        ADD_BUTTON(FA_MONEY_CHECK);
        ADD_BUTTON(FA_MONEY_CHECK_ALT);
        ADD_BUTTON(FA_MONUMENT);
        ADD_BUTTON(FA_MOON);
        ADD_BUTTON(FA_MORTAR_PESTLE);
        ADD_BUTTON(FA_MOSQUE);
        ADD_BUTTON(FA_MOTORCYCLE);
        ADD_BUTTON(FA_MOUNTAIN);
        ADD_BUTTON(FA_MOUSE_POINTER);
        ADD_BUTTON(FA_MUG_HOT);
        ADD_BUTTON(FA_MUSIC);
        ADD_BUTTON(FA_NETWORK_WIRED);
        ADD_BUTTON(FA_NEUTER);
        ADD_BUTTON(FA_NEWSPAPER);
        ADD_BUTTON(FA_NOT_EQUAL);
        ADD_BUTTON(FA_NOTES_MEDICAL);
        ADD_BUTTON(FA_OBJECT_GROUP);
        ADD_BUTTON(FA_OBJECT_UNGROUP);
        ADD_BUTTON(FA_OIL_CAN);
        ADD_BUTTON(FA_OM);
        ADD_BUTTON(FA_OTTER);
        ADD_BUTTON(FA_OUTDENT);
        ADD_BUTTON(FA_PAGER);
        ADD_BUTTON(FA_PAINT_BRUSH);
        ADD_BUTTON(FA_PAINT_ROLLER);
        ADD_BUTTON(FA_PALETTE);
        ADD_BUTTON(FA_PALLET);
        ADD_BUTTON(FA_PAPER_PLANE);
        ADD_BUTTON(FA_PAPERCLIP);
        ADD_BUTTON(FA_PARACHUTE_BOX);
        ADD_BUTTON(FA_PARAGRAPH);
        ADD_BUTTON(FA_PARKING);
        ADD_BUTTON(FA_PASSPORT);
        ADD_BUTTON(FA_PASTAFARIANISM);
        ADD_BUTTON(FA_PASTE);
        ADD_BUTTON(FA_PAUSE);
        ADD_BUTTON(FA_PAUSE_CIRCLE);
        ADD_BUTTON(FA_PAW);
        ADD_BUTTON(FA_PEACE);
        ADD_BUTTON(FA_PEN);
        ADD_BUTTON(FA_PEN_ALT);
        ADD_BUTTON(FA_PEN_FANCY);
        ADD_BUTTON(FA_PEN_NIB);
        ADD_BUTTON(FA_PEN_SQUARE);
        ADD_BUTTON(FA_PENCIL_ALT);
        ADD_BUTTON(FA_PENCIL_RULER);
        ADD_BUTTON(FA_PEOPLE_CARRY);
        ADD_BUTTON(FA_PEPPER_HOT);
        ADD_BUTTON(FA_PERCENT);
        ADD_BUTTON(FA_PERCENTAGE);
        ADD_BUTTON(FA_PERSON_BOOTH);
        ADD_BUTTON(FA_PHONE);
        ADD_BUTTON(FA_PHONE_ALT);
        ADD_BUTTON(FA_PHONE_SLASH);
        ADD_BUTTON(FA_PHONE_SQUARE);
        ADD_BUTTON(FA_PHONE_SQUARE_ALT);
        ADD_BUTTON(FA_PHONE_VOLUME);
        ADD_BUTTON(FA_PHOTO_VIDEO);
        ADD_BUTTON(FA_PIGGY_BANK);
        ADD_BUTTON(FA_PILLS);
        ADD_BUTTON(FA_PIZZA_SLICE);
        ADD_BUTTON(FA_PLACE_OF_WORSHIP);
        ADD_BUTTON(FA_PLANE);
        ADD_BUTTON(FA_PLANE_ARRIVAL);
        ADD_BUTTON(FA_PLANE_DEPARTURE);
        ADD_BUTTON(FA_PLAY);
        ADD_BUTTON(FA_PLAY_CIRCLE);
        ADD_BUTTON(FA_PLUG);
        ADD_BUTTON(FA_PLUS);
        ADD_BUTTON(FA_PLUS_CIRCLE);
        ADD_BUTTON(FA_PLUS_SQUARE);
        ADD_BUTTON(FA_PODCAST);
        ADD_BUTTON(FA_POLL);
        ADD_BUTTON(FA_POLL_H);
        ADD_BUTTON(FA_POO);
        ADD_BUTTON(FA_POO_STORM);
        ADD_BUTTON(FA_POOP);
        ADD_BUTTON(FA_PORTRAIT);
        ADD_BUTTON(FA_POUND_SIGN);
        ADD_BUTTON(FA_POWER_OFF);
        ADD_BUTTON(FA_PRAY);
        ADD_BUTTON(FA_PRAYING_HANDS);
        ADD_BUTTON(FA_PRESCRIPTION);
        ADD_BUTTON(FA_PRESCRIPTION_BOTTLE);
        ADD_BUTTON(FA_PRESCRIPTION_BOTTLE_ALT);
        ADD_BUTTON(FA_PRINT);
        ADD_BUTTON(FA_PROCEDURES);
        ADD_BUTTON(FA_PROJECT_DIAGRAM);
        ADD_BUTTON(FA_PUZZLE_PIECE);
        ADD_BUTTON(FA_QRCODE);
        ADD_BUTTON(FA_QUESTION);
        ADD_BUTTON(FA_QUESTION_CIRCLE);
        ADD_BUTTON(FA_QUIDDITCH);
        ADD_BUTTON(FA_QUOTE_LEFT);
        ADD_BUTTON(FA_QUOTE_RIGHT);
        ADD_BUTTON(FA_QURAN);
        ADD_BUTTON(FA_RADIATION);
        ADD_BUTTON(FA_RADIATION_ALT);
        ADD_BUTTON(FA_RAINBOW);
        ADD_BUTTON(FA_RANDOM);
        ADD_BUTTON(FA_RECEIPT);
        ADD_BUTTON(FA_RECYCLE);
        ADD_BUTTON(FA_REDO);
        ADD_BUTTON(FA_REDO_ALT);
        ADD_BUTTON(FA_REGISTERED);
        ADD_BUTTON(FA_REMOVE_FORMAT);
        ADD_BUTTON(FA_REPLY);
        ADD_BUTTON(FA_REPLY_ALL);
        ADD_BUTTON(FA_REPUBLICAN);
        ADD_BUTTON(FA_RESTROOM);
        ADD_BUTTON(FA_RETWEET);
        ADD_BUTTON(FA_RIBBON);
        ADD_BUTTON(FA_RING);
        ADD_BUTTON(FA_ROAD);
        ADD_BUTTON(FA_ROBOT);
        ADD_BUTTON(FA_ROCKET);
        ADD_BUTTON(FA_ROUTE);
        ADD_BUTTON(FA_RSS);
        ADD_BUTTON(FA_RSS_SQUARE);
        ADD_BUTTON(FA_RUBLE_SIGN);
        ADD_BUTTON(FA_RULER);
        ADD_BUTTON(FA_RULER_COMBINED);
        ADD_BUTTON(FA_RULER_HORIZONTAL);
        ADD_BUTTON(FA_RULER_VERTICAL);
        ADD_BUTTON(FA_RUNNING);
        ADD_BUTTON(FA_RUPEE_SIGN);
        ADD_BUTTON(FA_SAD_CRY);
        ADD_BUTTON(FA_SAD_TEAR);
        ADD_BUTTON(FA_SATELLITE);
        ADD_BUTTON(FA_SATELLITE_DISH);
        ADD_BUTTON(FA_SAVE);
        ADD_BUTTON(FA_SCHOOL);
        ADD_BUTTON(FA_SCREWDRIVER);
        ADD_BUTTON(FA_SCROLL);
        ADD_BUTTON(FA_SD_CARD);
        ADD_BUTTON(FA_SEARCH);
        ADD_BUTTON(FA_SEARCH_DOLLAR);
        ADD_BUTTON(FA_SEARCH_LOCATION);
        ADD_BUTTON(FA_SEARCH_MINUS);
        ADD_BUTTON(FA_SEARCH_PLUS);
        ADD_BUTTON(FA_SEEDLING);
        ADD_BUTTON(FA_SERVER);
        ADD_BUTTON(FA_SHAPES);
        ADD_BUTTON(FA_SHARE);
        ADD_BUTTON(FA_SHARE_ALT);
        ADD_BUTTON(FA_SHARE_ALT_SQUARE);
        ADD_BUTTON(FA_SHARE_SQUARE);
        ADD_BUTTON(FA_SHEKEL_SIGN);
        ADD_BUTTON(FA_SHIELD_ALT);
        ADD_BUTTON(FA_SHIP);
        ADD_BUTTON(FA_SHIPPING_FAST);
        ADD_BUTTON(FA_SHOE_PRINTS);
        ADD_BUTTON(FA_SHOPPING_BAG);
        ADD_BUTTON(FA_SHOPPING_BASKET);
        ADD_BUTTON(FA_SHOPPING_CART);
        ADD_BUTTON(FA_SHOWER);
        ADD_BUTTON(FA_SHUTTLE_VAN);
        ADD_BUTTON(FA_SIGN);
        ADD_BUTTON(FA_SIGN_IN_ALT);
        ADD_BUTTON(FA_SIGN_LANGUAGE);
        ADD_BUTTON(FA_SIGN_OUT_ALT);
        ADD_BUTTON(FA_SIGNAL);
        ADD_BUTTON(FA_SIGNATURE);
        ADD_BUTTON(FA_SIM_CARD);
        ADD_BUTTON(FA_SITEMAP);
        ADD_BUTTON(FA_SKATING);
        ADD_BUTTON(FA_SKIING);
        ADD_BUTTON(FA_SKIING_NORDIC);
        ADD_BUTTON(FA_SKULL);
        ADD_BUTTON(FA_SKULL_CROSSBONES);
        ADD_BUTTON(FA_SLASH);
        ADD_BUTTON(FA_SLEIGH);
        ADD_BUTTON(FA_SLIDERS_H);
        ADD_BUTTON(FA_SMILE);
        ADD_BUTTON(FA_SMILE_BEAM);
        ADD_BUTTON(FA_SMILE_WINK);
        ADD_BUTTON(FA_SMOG);
        ADD_BUTTON(FA_SMOKING);
        ADD_BUTTON(FA_SMOKING_BAN);
        ADD_BUTTON(FA_SMS);
        ADD_BUTTON(FA_SNOWBOARDING);
        ADD_BUTTON(FA_SNOWFLAKE);
        ADD_BUTTON(FA_SNOWMAN);
        ADD_BUTTON(FA_SNOWPLOW);
        ADD_BUTTON(FA_SOCKS);
        ADD_BUTTON(FA_SOLAR_PANEL);
        ADD_BUTTON(FA_SORT);
        ADD_BUTTON(FA_SORT_ALPHA_DOWN);
        ADD_BUTTON(FA_SORT_ALPHA_DOWN_ALT);
        ADD_BUTTON(FA_SORT_ALPHA_UP);
        ADD_BUTTON(FA_SORT_ALPHA_UP_ALT);
        ADD_BUTTON(FA_SORT_AMOUNT_DOWN);
        ADD_BUTTON(FA_SORT_AMOUNT_DOWN_ALT);
        ADD_BUTTON(FA_SORT_AMOUNT_UP);
        ADD_BUTTON(FA_SORT_AMOUNT_UP_ALT);
        ADD_BUTTON(FA_SORT_DOWN);
        ADD_BUTTON(FA_SORT_NUMERIC_DOWN);
        ADD_BUTTON(FA_SORT_NUMERIC_DOWN_ALT);
        ADD_BUTTON(FA_SORT_NUMERIC_UP);
        ADD_BUTTON(FA_SORT_NUMERIC_UP_ALT);
        ADD_BUTTON(FA_SORT_UP);
        ADD_BUTTON(FA_SPA);
        ADD_BUTTON(FA_SPACE_SHUTTLE);
        ADD_BUTTON(FA_SPELL_CHECK);
        ADD_BUTTON(FA_SPIDER);
        ADD_BUTTON(FA_SPINNER);
        ADD_BUTTON(FA_SPLOTCH);
        ADD_BUTTON(FA_SPRAY_CAN);
        ADD_BUTTON(FA_SQUARE);
        ADD_BUTTON(FA_SQUARE_FULL);
        ADD_BUTTON(FA_SQUARE_ROOT_ALT);
        ADD_BUTTON(FA_STAMP);
        ADD_BUTTON(FA_STAR);
        ADD_BUTTON(FA_STAR_AND_CRESCENT);
        ADD_BUTTON(FA_STAR_HALF);
        ADD_BUTTON(FA_STAR_HALF_ALT);
        ADD_BUTTON(FA_STAR_OF_DAVID);
        ADD_BUTTON(FA_STAR_OF_LIFE);
        ADD_BUTTON(FA_STEP_BACKWARD);
        ADD_BUTTON(FA_STEP_FORWARD);
        ADD_BUTTON(FA_STETHOSCOPE);
        ADD_BUTTON(FA_STICKY_NOTE);
        ADD_BUTTON(FA_STOP);
        ADD_BUTTON(FA_STOP_CIRCLE);
        ADD_BUTTON(FA_STOPWATCH);
        ADD_BUTTON(FA_STORE);
        ADD_BUTTON(FA_STORE_ALT);
        ADD_BUTTON(FA_STREAM);
        ADD_BUTTON(FA_STREET_VIEW);
        ADD_BUTTON(FA_STRIKETHROUGH);
        ADD_BUTTON(FA_STROOPWAFEL);
        ADD_BUTTON(FA_SUBSCRIPT);
        ADD_BUTTON(FA_SUBWAY);
        ADD_BUTTON(FA_SUITCASE);
        ADD_BUTTON(FA_SUITCASE_ROLLING);
        ADD_BUTTON(FA_SUN);
        ADD_BUTTON(FA_SUPERSCRIPT);
        ADD_BUTTON(FA_SURPRISE);
        ADD_BUTTON(FA_SWATCHBOOK);
        ADD_BUTTON(FA_SWIMMER);
        ADD_BUTTON(FA_SWIMMING_POOL);
        ADD_BUTTON(FA_SYNAGOGUE);
        ADD_BUTTON(FA_SYNC);
        ADD_BUTTON(FA_SYNC_ALT);
        ADD_BUTTON(FA_SYRINGE);
        ADD_BUTTON(FA_TABLE);
        ADD_BUTTON(FA_TABLE_TENNIS);
        ADD_BUTTON(FA_TABLET);
        ADD_BUTTON(FA_TABLET_ALT);
        ADD_BUTTON(FA_TABLETS);
        ADD_BUTTON(FA_TACHOMETER_ALT);
        ADD_BUTTON(FA_TAG);
        ADD_BUTTON(FA_TAGS);
        ADD_BUTTON(FA_TAPE);
        ADD_BUTTON(FA_TASKS);
        ADD_BUTTON(FA_TAXI);
        ADD_BUTTON(FA_TEETH);
        ADD_BUTTON(FA_TEETH_OPEN);
        ADD_BUTTON(FA_TEMPERATURE_HIGH);
        ADD_BUTTON(FA_TEMPERATURE_LOW);
        ADD_BUTTON(FA_TENGE);
        ADD_BUTTON(FA_TERMINAL);
        ADD_BUTTON(FA_TEXT_HEIGHT);
        ADD_BUTTON(FA_TEXT_WIDTH);
        ADD_BUTTON(FA_TH);
        ADD_BUTTON(FA_TH_LARGE);
        ADD_BUTTON(FA_TH_LIST);
        ADD_BUTTON(FA_THEATER_MASKS);
        ADD_BUTTON(FA_THERMOMETER);
        ADD_BUTTON(FA_THERMOMETER_EMPTY);
        ADD_BUTTON(FA_THERMOMETER_FULL);
        ADD_BUTTON(FA_THERMOMETER_HALF);
        ADD_BUTTON(FA_THERMOMETER_QUARTER);
        ADD_BUTTON(FA_THERMOMETER_THREE_QUARTERS);
        ADD_BUTTON(FA_THUMBS_DOWN);
        ADD_BUTTON(FA_THUMBS_UP);
        ADD_BUTTON(FA_THUMBTACK);
        ADD_BUTTON(FA_TICKET_ALT);
        ADD_BUTTON(FA_TIMES);
        ADD_BUTTON(FA_TIMES_CIRCLE);
        ADD_BUTTON(FA_TINT);
        ADD_BUTTON(FA_TINT_SLASH);
        ADD_BUTTON(FA_TIRED);
        ADD_BUTTON(FA_TOGGLE_OFF);
        ADD_BUTTON(FA_TOGGLE_ON);
        ADD_BUTTON(FA_TOILET);
        ADD_BUTTON(FA_TOILET_PAPER);
        ADD_BUTTON(FA_TOOLBOX);
        ADD_BUTTON(FA_TOOLS);
        ADD_BUTTON(FA_TOOTH);
        ADD_BUTTON(FA_TORAH);
        ADD_BUTTON(FA_TORII_GATE);
        ADD_BUTTON(FA_TRACTOR);
        ADD_BUTTON(FA_TRADEMARK);
        ADD_BUTTON(FA_TRAFFIC_LIGHT);
        ADD_BUTTON(FA_TRAIN);
        ADD_BUTTON(FA_TRAM);
        ADD_BUTTON(FA_TRANSGENDER);
        ADD_BUTTON(FA_TRANSGENDER_ALT);
        ADD_BUTTON(FA_TRASH);
        ADD_BUTTON(FA_TRASH_ALT);
        ADD_BUTTON(FA_TRASH_RESTORE);
        ADD_BUTTON(FA_TRASH_RESTORE_ALT);
        ADD_BUTTON(FA_TREE);
        ADD_BUTTON(FA_TROPHY);
        ADD_BUTTON(FA_TRUCK);
        ADD_BUTTON(FA_TRUCK_LOADING);
        ADD_BUTTON(FA_TRUCK_MONSTER);
        ADD_BUTTON(FA_TRUCK_MOVING);
        ADD_BUTTON(FA_TRUCK_PICKUP);
        ADD_BUTTON(FA_TSHIRT);
        ADD_BUTTON(FA_TTY);
        ADD_BUTTON(FA_TV);
        ADD_BUTTON(FA_UMBRELLA);
        ADD_BUTTON(FA_UMBRELLA_BEACH);
        ADD_BUTTON(FA_UNDERLINE);
        ADD_BUTTON(FA_UNDO);
        ADD_BUTTON(FA_UNDO_ALT);
        ADD_BUTTON(FA_UNIVERSAL_ACCESS);
        ADD_BUTTON(FA_UNIVERSITY);
        ADD_BUTTON(FA_UNLINK);
        ADD_BUTTON(FA_UNLOCK);
        ADD_BUTTON(FA_UNLOCK_ALT);
        ADD_BUTTON(FA_UPLOAD);
        ADD_BUTTON(FA_USER);
        ADD_BUTTON(FA_USER_ALT);
        ADD_BUTTON(FA_USER_ALT_SLASH);
        ADD_BUTTON(FA_USER_ASTRONAUT);
        ADD_BUTTON(FA_USER_CHECK);
        ADD_BUTTON(FA_USER_CIRCLE);
        ADD_BUTTON(FA_USER_CLOCK);
        ADD_BUTTON(FA_USER_COG);
        ADD_BUTTON(FA_USER_EDIT);
        ADD_BUTTON(FA_USER_FRIENDS);
        ADD_BUTTON(FA_USER_GRADUATE);
        ADD_BUTTON(FA_USER_INJURED);
        ADD_BUTTON(FA_USER_LOCK);
        ADD_BUTTON(FA_USER_MD);
        ADD_BUTTON(FA_USER_MINUS);
        ADD_BUTTON(FA_USER_NINJA);
        ADD_BUTTON(FA_USER_NURSE);
        ADD_BUTTON(FA_USER_PLUS);
        ADD_BUTTON(FA_USER_SECRET);
        ADD_BUTTON(FA_USER_SHIELD);
        ADD_BUTTON(FA_USER_SLASH);
        ADD_BUTTON(FA_USER_TAG);
        ADD_BUTTON(FA_USER_TIE);
        ADD_BUTTON(FA_USER_TIMES);
        ADD_BUTTON(FA_USERS);
        ADD_BUTTON(FA_USERS_COG);
        ADD_BUTTON(FA_UTENSIL_SPOON);
        ADD_BUTTON(FA_UTENSILS);
        ADD_BUTTON(FA_VECTOR_SQUARE);
        ADD_BUTTON(FA_VENUS);
        ADD_BUTTON(FA_VENUS_DOUBLE);
        ADD_BUTTON(FA_VENUS_MARS);
        ADD_BUTTON(FA_VIAL);
        ADD_BUTTON(FA_VIALS);
        ADD_BUTTON(FA_VIDEO);
        ADD_BUTTON(FA_VIDEO_SLASH);
        ADD_BUTTON(FA_VIHARA);
        ADD_BUTTON(FA_VOICEMAIL);
        ADD_BUTTON(FA_VOLLEYBALL_BALL);
        ADD_BUTTON(FA_VOLUME_DOWN);
        ADD_BUTTON(FA_VOLUME_MUTE);
        ADD_BUTTON(FA_VOLUME_OFF);
        ADD_BUTTON(FA_VOLUME_UP);
        ADD_BUTTON(FA_VOTE_YEA);
        ADD_BUTTON(FA_VR_CARDBOARD);
        ADD_BUTTON(FA_WALKING);
        ADD_BUTTON(FA_WALLET);
        ADD_BUTTON(FA_WAREHOUSE);
        ADD_BUTTON(FA_WATER);
        ADD_BUTTON(FA_WAVE_SQUARE);
        ADD_BUTTON(FA_WEIGHT);
        ADD_BUTTON(FA_WEIGHT_HANGING);
        ADD_BUTTON(FA_WHEELCHAIR);
        ADD_BUTTON(FA_WIFI);
        ADD_BUTTON(FA_WIND);
        ADD_BUTTON(FA_WINDOW_CLOSE);
        ADD_BUTTON(FA_WINDOW_MAXIMIZE);
        ADD_BUTTON(FA_WINDOW_MINIMIZE);
        ADD_BUTTON(FA_WINDOW_RESTORE);
        ADD_BUTTON(FA_WINE_BOTTLE);
        ADD_BUTTON(FA_WINE_GLASS);
        ADD_BUTTON(FA_WINE_GLASS_ALT);
        ADD_BUTTON(FA_WON_SIGN);
        ADD_BUTTON(FA_WRENCH);
        ADD_BUTTON(FA_X_RAY);
        ADD_BUTTON(FA_YEN_SIGN);
        ADD_BUTTON(FA_YIN_YANG);
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////

        screen->perform_layout();
        screen->set_visible(true);

        nanogui::mainloop();
    }

    nanogui::shutdown();
    return 0;
}
