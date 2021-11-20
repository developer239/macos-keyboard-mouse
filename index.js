var addon = require('bindings')({
  bindings: 'macos-keyboard-mouse', try: [['module_root', 'cpp', 'build', 'Release', 'bindings']] // TODO: figure out a better way to do this?
})

const mouse = new addon.Mouse()
mouse.setDelay(1)

const twoPI = Math.PI * 2.0;
const height = 500
const width = 500

for (let x = 0; x < width; x++)
{
  const y = height * Math.sin((twoPI * x) / width) + height;
  mouse.move(x, y);
}
