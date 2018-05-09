import types


class Sequence:
    def __init__(self, *args):
        if isinstance(args[0], types.GeneratorType):
            self.generator = args[0]
        else:
            def generator():
                for it in args[0]:
                    yield it

            self.generator = generator()

    def select(self, func):
        gen = self.generator

        def tmp():
            for it in gen:
                yield func(it)

        self.generator = tmp()
        return self

    def take(self, n):
        gen = self.generator

        def tmp():
            for i in range(n):
                yield next(gen)

        self.generator = tmp()
        return self

    def to_list(self):
        return list(self.generator)

    def where(self, func):
        gen = self.generator

        def tmp():
            for it in gen:
                if func(it):
                    yield it

        self.generator = tmp()
        return self
