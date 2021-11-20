const addon = require('bindings')({
  bindings: 'macos-keyboard-mouse',
  // TODO: figure out a better way to do this?
  try: [['module_root', 'cpp', 'build', 'Release', 'bindings']]
})

module.exports = {
  Keyboard: addon.Keyboard,
  Mouse: addon.Mouse
}
