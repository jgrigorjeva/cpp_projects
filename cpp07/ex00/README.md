# Templates

normally you could call the function template like a regular function:
```
swap(a, b);
min(i, j);
```
The problem arises when calling the min() template on string arguments, since the there already is a function taking str arguments:
function template "const _Tp &std::min(const _Tp &__a, const _Tp &__b)" (declared at line 230 of "/usr/include/c++/12/bits/stl_algobase.h"), we need to distinguish between them. Therefore, our templates are called from the local namespace (as suggested in the subject)

```
::swap(a, b);
::min(i, j);
```
