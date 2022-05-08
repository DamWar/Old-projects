import math
import cupy as cp


class InputManager:
    def __init__(self):
        self.sample_size: int = 0
        self.sample_digits = 0
        self.array_size = 100000
        self.choice = 'z'
        self.is_safe = False
        print('Welcome to pi approximation program.\nThis program uses Monte Carlo method.')
        print('For optimization purposes, you can only select numbers with single digit[1-9] followed by zeros')
        self.default_behaviour()
        self.is_safe = True
        """TODO advanced options
        while self.choice != 'd' and self.choice != 'a':
            self.choice = input('Would you like to choose default behaviour or set up advanced one?(d/a): ')
        if self.choice == 'd':
            self.default_behaviour()
            self.is_safe = True
        elif self.choice == 'a':
            self.advanced_behaviour()
        """

    def default_behaviour(self):
        while not(1 <= int(self.sample_size) <= 9):
            self.sample_size = int(input('What should be the first digit defining number of points?[1-9]: '))
        while int(self.sample_digits < 3):
            self.sample_digits = int(input('How many zeros?(digit*10^n, at least 3): '))
        while int(self.sample_digits) > 0:
            self.sample_size *= 10
            self.sample_digits -= 1
        while int(self.sample_size) < (1000 * self.array_size) and self.array_size > 1:
            self.array_size /= 10
            math.floor(self.array_size)

    def advanced_behaviour(self):
        # TODO
        print('To be implemented.\n')


class PiMonte:
    def __init__(self, sample_size, array_size):
        self.sample_size = sample_size
        self.array_size = array_size
        self.array_quantity = int(sample_size/array_size)
        self.array_percentage = self.array_quantity / 1000
        self.percentage_done = 0
        self.approx_avg = 0
        self.origin_distance = 0
        self.in_circle = 0
        self.numberOfExecutions = 0

    def approximate(self):
        for x in range(1000):
            print(str(round(self.percentage_done, 1)) + '%')
            for y in range(int(self.array_percentage)):
                self.numberOfExecutions += 1
                rand_x = cp.random.uniform(-1.0, 1.0, self.array_size)
                rand_y = cp.random.uniform(-1.0, 1.0, self.array_size)
                rand_x = cp.square(rand_x)
                rand_y = cp.square(rand_y)

                origin_distance = cp.add(rand_x, rand_y)
                in_circle = cp.count_nonzero(origin_distance <= 1)

                self.approx_avg += 4 * in_circle / self.array_size
            self.percentage_done += 0.1
        self.approx_avg /= self.array_quantity


if __name__ == '__main__':
    data = InputManager()
    if data.is_safe:
        pi = PiMonte(int(data.sample_size), int(data.array_size))
        pi.approximate()
        print('Number of points generated: ' + str(math.floor(data.sample_size)))
        print('Approximated pi number: ' + str(pi.approx_avg))
