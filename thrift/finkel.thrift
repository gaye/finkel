
struct Bitmap {
  // TODO(gareth): Add Bitmap fields
}

struct KeyboardInput {
  1: string text;
}

struct MouseInput {
  1: i32 x;
  2: i32 y;
  3: bool doubleClick;
}

union UserInput {
  1: KeyboardInput keyboardInput;
  2: MouseInput mouseInput;
}

service Finkel {
  /**
   * @return {bool} Whether or not Magic Online started successfully.
   */
  bool start();

  /**
   * @return {bool} Whether or not Magic Online stopped successfully.
   */
  bool stop();

  /**
   * @return {Bitmap} Screenshot of Magic Online.
   */
  Bitmap TakeScreenshot();

  /**
   * @return {bool} Whether or not the input sequence succeeded.
   */
  bool ProcessUserInput(1: list<UserInput> inputSequence);
}
