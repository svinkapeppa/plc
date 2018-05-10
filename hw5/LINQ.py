import types


class Sequence:
    """
        Special class, which enables usage of LINQ
    """

    def __init__(self, *args):
        """
            Creates generator (if args[0] is a generator, than it is taken as it is,
            if args[0] is a sequence of any kind, then it is converted to generator,
            otherwise an error will occur).
        """
        if isinstance(args[0], types.GeneratorType):
            self.generator = args[0]
        else:
            def generator():
                for it in args[0]:
                    yield it

            self.generator = generator()

    def group_by(self, func):
        gen = self.generator
        d = {}

        def tmp():
            for it in gen:
                if func(it) in d:
                    d[func(it)].append(it)
                else:
                    d[func(it)] = [it, ]
            for it in list(d.items()):
                yield it

        self.generator = tmp()
        return self

    def flatten(self):
        gen = self.generator

        def tmp():
            for it in gen:
                for elem in it:
                    yield elem

        self.generator = tmp()
        return self

    def order_by(self, func):
        arr = sorted(list(self.generator), key=func)

        def tmp():
            for it in arr:
                yield it

        self.generator = tmp()
        return self

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
