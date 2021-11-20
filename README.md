# MacOS Keyboard Mouse

[![npm version](http://img.shields.io/npm/v/create-opinionated-app.svg?style=flat)](https://www.npmjs.com/package/macos-keyboard-mouse "View this project on npm")

Keyboard and mouse controls for your Node project. Currently, supports only Mac.

## Libraries:

- [node-addon-api](https://github.com/nodejs/node-addon-api) - interface for building native addons
- [cmake-js](https://github.com/cmake-js/cmake-js) - native addon build tool which works like `node-gyp`

## Example

### Mouse

```js
import { Mouse } from 'macos-keyboard-mouse';

const mouse = new Mouse();

// sets delay between pixels
mouse.setDelay(16);

// moves mouse to x: 100, y: 100
mouse.move(100, 100);
```

### Keyboard

```js
import { Keyboard } from 'macos-keyboard-mouse';

const keyboard = new Keyboard();

// types 'hello world' 
keyboard.type('Hello world');
```
