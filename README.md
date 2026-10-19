# Day 1 — Fixed-Capacity Integer Ring Buffer
Implementation of a ring buffer that storages integers in a fixed size.

## Compilation
```bash
cmake -S . -B build
cmake --build build
```

## Tests
```bash
ctest --test-dir build --output-on-failure -V
```

## Index
- `head`: index of the oldest element in the buffer. This is the elemnent eliminated when a pop occurs.
- `tail`: index where a new element (push) will be stored.

## Invariants

- `size <= INT_RING_CAPACITY`: there won't be more elements stored than the capacity of it.
- `head < INT_RING_CAPACITY`: lecture index always points to a valid position
- `tail < INT_RING_CAPACITY`: write index always point to a valid position

## Questions

1. Why are head and tail insufficient by themselves to distinguish a
full buffer from an empty buffer in this design?
- Because when the bufffer is either full or empty, head and tail are the same
2. What does each field represent immediately before and after a
successful pop?
- head: this index moves, pointing to the next oldest element.
- tail: this index does not change, points to the next slot to write
- size: the value decreases by 1, showing the amount of elements in the buffer
3. Why is writing to data[INT_RING_CAPACITY] invalid even though the
address is one position past the array?
- Because arrays indices start at 0 and end at caoacity minus 1. INT_RING_CAPACITY is not a valid index.
4. Which invariants must be true after every public function returns?
- 0 <= head < INT_RING_CAPACITY
- 0 <= tail < INT_RING CAPACITY
5. What is the time complexity of push, pop, and peek?
- The time complexity is O(1). None of these operations sort the elements in the buffer