const addon = require('bindings')({
  bindings: 'macos-keyboard-mouse',
  try: [['module_root', 'cpp', 'build', 'Release', 'bindings']] // TODO: figure out a better way to do this?
})

export const Keyboard = addon.Keyboard

export const Mouse = addon.Mouse
