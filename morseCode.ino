#define BLUE 3
#define GREEN 5
#define RED 6
#define TIME_UNIT 100

void writeAll(int val) {
  analogWrite(BLUE, val);
  analogWrite(GREEN, val);
  analogWrite(RED, val);
}

void dah() {
  writeAll(50);
  delay(3 * TIME_UNIT);
  writeAll(0);
  delay(TIME_UNIT);
}

void dit() {
  writeAll(50);
  delay(TIME_UNIT);
  writeAll(0);
  delay(TIME_UNIT);
}

typedef void (*fn)(void);

struct code {
  fn sequence[5];
};

code letters[26];
code numbers[10];

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  letters['a' - 'a'] = { &dit, &dah };
  letters['b' - 'a'] = { &dah, &dit, &dit, &dit };
  letters['c' - 'a'] = { &dah, &dit, &dah, &dit };
  letters['d' - 'a'] = { &dah, &dit, &dit };
  letters['e' - 'a'] = { &dit };
  letters['f' - 'a'] = { &dit, &dit, &dah, &dit };
  letters['g' - 'a'] = { &dah, &dah, &dit };
  letters['h' - 'a'] = { &dit, &dit, &dit, &dit };
  letters['i' - 'a'] = { &dit, &dit };
  letters['j' - 'a'] = { &dit, &dah, &dah, &dah };
  letters['k' - 'a'] = { &dah, &dit, &dah };
  letters['l' - 'a'] = { &dit, &dah, &dit, &dit };
  letters['m' - 'a'] = { &dah, &dah };
  letters['n' - 'a'] = { &dah, &dit };
  letters['o' - 'a'] = { &dah, &dah, &dah };
  letters['p' - 'a'] = { &dit, &dah, &dah, &dit };
  letters['q' - 'a'] = { &dah, &dah, &dit, &dah };
  letters['r' - 'a'] = { &dit, &dah, &dit };
  letters['s' - 'a'] = { &dit, &dit, &dit };
  letters['t' - 'a'] = { &dah };
  letters['u' - 'a'] = { &dit, &dit, &dah };
  letters['v' - 'a'] = { &dit, &dit, &dit, &dah };
  letters['w' - 'a'] = { &dit, &dah, &dah };
  letters['x' - 'a'] = { &dah, &dit, &dit, &dah };
  letters['y' - 'a'] = { &dah, &dit, &dah, &dah };
  letters['z' - 'a'] = { &dah, &dah, &dit, &dit };
  numbers['0' - '0'] = { &dah, &dah, &dah, &dah, &dah };
  numbers['1' - '0'] = { &dit, &dah, &dah, &dah, &dah };
  numbers['2' - '0'] = { &dit, &dit, &dah, &dah, &dah };
  numbers['3' - '0'] = { &dit, &dit, &dit, &dah, &dah };
  numbers['3' - '0'] = { &dit, &dit, &dit, &dit, &dah };
  numbers['4' - '0'] = { &dit, &dit, &dit, &dit, &dah };
  numbers['5' - '0'] = { &dit, &dit, &dit, &dit, &dit };
  numbers['6' - '0'] = { &dah, &dit, &dit, &dit, &dah };
  numbers['7' - '0'] = { &dah, &dah, &dit, &dit, &dah };
  numbers['8' - '0'] = { &dah, &dah, &dah, &dit, &dah };
  numbers['9' - '0'] = { &dah, &dah, &dah, &dah, &dah };
  writeAll(0);
}

void loop()
{
  char message[]{ "abcdefghijklmnopqrstuvwxyz 1234567890" };
  for (size_t i{ 0 }; i < sizeof(message); i++) {
    int alphaIndex{ tolower(message[i]) - 'a' };
    int numIndex{ message[i] - '0' };
    bool isNumber{ numIndex >= 0 && numIndex <= 10 };

    if ((alphaIndex >= 0 && alphaIndex <= 25) || isNumber) {
      const code &character = (isNumber ? numbers : letters)[isNumber ? numIndex : alphaIndex];

      for (size_t j{ 0 }; j < 5; j++) {
        if (character.sequence[j] == nullptr) break;
        character.sequence[j]();
      }
      delay(3 * TIME_UNIT);
    }

    if (message[i] == ' ') {
      delay(7 * TIME_UNIT);
    }
  }

  delay(14 * TIME_UNIT);
}
