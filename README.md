# Cat Math
MooncatCorps' collection of mathematical functions and objects for precise
development.

Please wait while the README is expanded.

## Naming Conventions
For each entity, certain conventions are followed to avoid function
overloading and thus allowing language compatibility and, more importantly,
avoiding that which should never have existed.

### Class methods

#### General
| Convention            | Effect |
| --------------------- | ------ |
| Noun                  | Returns a new object or value
| Verb                  | Modifies the current object

### Entity Specific
#### Vectors

| Convention      | Effect |
| --------------- | ------ |
| No Suffix       | Applies the same operation to all components equally
| Suffix `_x`     | Applies the operation to the x-component
| Suffix `_y`     | Applies the operation to the y-component
| Suffix `_z`     | Applies the operation to the z-component
| Suffix `_xy`    | Applies two different operations, one for x and one for y
| Suffix `_xyz`   | Applies three different operations one for x, one for y and one for z
| Suffix `_fxy`   | Applies the same operation to the x and y components
| Suffix `_fxyz`  | Applies the same operation to the x, y and z components
| Suffix `_fxy_z` | Applies the same operation to x and y, and a separate one for z
| Suffix `_fxz_y` | Applies one same operation to x and z, and a separate one for y
| Suffix `_fyz_x` | Applies one same operation to y and z, and a separate one for x

> [!NOTE]  
> Vector methods with suffixes will usually be accompanied by an equal amount of parameter sets
> If a method has an `_f` suffix it will use one parameter set for all f-marked components

> [!TIP]
> `_f` suffixes exist to reduce ambiguity, such as in the case of `vector2::add` and `vector2::add_fxy`

