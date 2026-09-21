import sys

n_books, bookshelf_height, bookshelf_width = sys.stdin.readline().split(sep=" ")

books = {}


for i in range(int(n_books)):
    height, thickness = sys.stdin.readline().split(sep=" ")
    books[f"{i+1}"] = (int(height), int(thickness))

print(books)
# 3 250 350
# 178 32
# 200 60
# 297 50
# max book height that fits the bookshelf height.
# implement
values = books.values()
print(values)
print(type(values))
# max book height that fits bookshelf width after height has been decided.
# implement

# you essentially have two categories:

# * Category 1: `178, 200, 297` → max = **297**, min = **178**
# * Category 2: `32, 60, 50` → max = **60**, min = **32**

# ### If you want the n largest/smallest from each category

# A very clean approach is to use `zip` to transpose the data:

# ```python
# values = [(178, 32), (200, 60), (297, 50)]

# categories = list(zip(*values))

# max_values = [max(category) for category in categories]
# min_values = [min(category) for category in categories]

# print(max_values)  # [297, 60]
# print(min_values)  # [178, 32]
# ```

# So you don't necessarily need a dict. A **list of tuples** is actually a very natural structure for this.

# ### If you want the top `n` values

# For example, top 2 values in each category:

# ```python
# values = [(178, 32), (200, 60), (297, 50)]

# categories = zip(*values)

# n = 2

# top_n = [sorted(category, reverse=True)[:n] for category in categories]

# print(top_n)
# # [[297, 200], [60, 50]]
# ```

# And bottom 2:

# ```python
# bottom_n = [sorted(category)[:n] for category in zip(*values)]

# print(bottom_n)
# # [[178, 200], [32, 50]]
# ```

# ### If your actual goal is slightly different

# If by "maxed together" you mean that you want to **compare the tuples based on the maximum of each category**, e.g. determine which tuple/category wins, then the solution is different.

# For example, if you have many tuples like:

# ```python
# values = [
#     (178, 32),
#     (200, 60),
#     (297, 50),
# ]
# ```

# and you want to identify **which values are the top N for each position while retaining their original tuples**, I can show you a particularly clean solution for that too.

