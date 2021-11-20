export interface IPoint {
  x: number;
  y: number;
}

export enum Button {
  left,
  right,
  center,
}

export class Keyboard {
  type(query: string): void
  click(key: string): void
  clickEnter(): void
}

export class Mouse {
  move(x: number, y: number): void
  press(button: Button, isDown: boolean): void
  pressLeft(): void
  pressRight(): void
  setDelay(ms: number ): void
  getLocation(): IPoint
}
