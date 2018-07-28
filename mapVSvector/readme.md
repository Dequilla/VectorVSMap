# Vector VS Map VS Unordered Map
A test to see which of these are fastest to iterate through(as if they all where vectors)

## Conclusion
Using the C++11 For In Range loop (ex: for(auto& obj : objects)) vector is slightly faster than unordered_map, but not by much, however a normal map takes atleast double to time.