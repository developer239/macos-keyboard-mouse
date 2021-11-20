var addon = require('bindings')({
  bindings: 'macos-keyboard-mouse',
  try: [['module_root', 'cpp', 'build', 'Release', 'bindings']] // TODO: figure out a better way to do this?
})

console.log('addon', addon)

const mouse = new addon.Mouse(1)
console.log('default', 1)
console.log('expected 2, result', mouse.add(2))
