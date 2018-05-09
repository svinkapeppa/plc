from LINQ import *


def fibonacci():
    a, b = 1, 1
    while True:
        yield a
        a, b = b, a + b


def main():
    print(Sequence(fibonacci()).select(lambda x: x ** 2).take(13).where(lambda x: x % 2 == 1).to_list())


if __name__ == '__main__':
    main()
