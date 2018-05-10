import re

from LINQ import *


def fibonacci():
    a, b = 1, 1
    while True:
        yield a
        a, b = b, a + b


def text():
    with open('text/sample.txt', encoding='utf-8') as f:
        for line in f:
            line = re.sub('[^a-zA-Z0-9]', ' ', line)
            for word in line.strip().split():
                if len(word) != 0:
                    yield word


def main():
    print('FIRST TASK')
    print(Sequence(fibonacci())
          .where(lambda x: x % 3 == 0)
          .select(lambda x: x ** 2 if x % 2 == 0 else x)
          .take(5)
          .to_list())

    print('\nSECOND TASK')
    print(Sequence(text())
          .group_by(lambda x: x)
          .select(lambda x: (x[0], len(x[1])))
          .order_by(lambda x: x[0])
          .order_by(lambda x: -x[1])
          .take(10)
          .to_list())


if __name__ == '__main__':
    main()
