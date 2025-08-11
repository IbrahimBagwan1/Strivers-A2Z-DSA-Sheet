import os
import re

# List of folder names as per the image
folders = [
    "Step 1 Learn the basics",
    "Step 2 Learn Important Sorting Techniques",
    "Step 3 Solve Problems on Arrays [Easy -> Medium -> Hard]",
    "Step 4 Binary Search [1D, 2D Arrays, Search Space]",
    "Step 5 Strings [Basic and Medium]",
    "Step 6 Learn LinkedList [Single LL, Double LL, Medium, Hard Problems]",
    "Step 7 Recursion [PatternWise]",
    "Step 8 Bit Manipulation [Concepts & Problems]",
    "Step 9 Stack and Queues [Learning, Pre-In-Post-fix, Monotonic Stack, Implementation]",
    "Step 10 Sliding Window & Two Pointer Combined Problems",
    "Step 11 Heaps [Learning, Medium, Hard Problems]",
    "Step 12 Greedy Algorithms [Easy, Medium/Hard]",
    "Step 13 Binary Trees [Traversal, Medium and Hard Problems]",
    "Step 14 Binary Search Trees [Concept and Problems]",
    "Step 15 Graphs [Concepts & Problems]",
    "Step 16 Dynamic Programming [Patterns and Problems]",
    "Step 17 Tries",
    "Step 18 Strings"
]

# Function to sanitize folder names
def sanitize(name):
    # Remove or replace invalid Windows characters
    return re.sub(r'[<>:"/\\|?*]', '', name)

base_path = os.path.dirname(os.path.abspath(__file__))

for folder in folders:
    safe_name = sanitize(folder)
    folder_path = os.path.join(base_path, safe_name)
    os.makedirs(folder_path, exist_ok=True)

print("✅ All folders created successfully.")
