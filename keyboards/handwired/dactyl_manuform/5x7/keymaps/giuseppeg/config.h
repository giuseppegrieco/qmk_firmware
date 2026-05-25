#pragma once

#define MASTER_LEFT

// Mod-tap timing: hold a mod-tap key longer than this (ms) → modifier,
// shorter → the underlying keycode. Default is 200; 180 makes mods
// trigger slightly faster, which helps if you find yourself getting
// letters when you meant a mod.
#define TAPPING_TERM 180

// If another key is pressed AND released while a mod-tap is held,
// commit the mod-tap to its hold (modifier) interpretation — even if
// it happened faster than TAPPING_TERM. Makes fast Ctrl+S work; can
// occasionally misfire on natural finger rolls.
#define PERMISSIVE_HOLD
