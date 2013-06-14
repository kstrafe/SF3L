SF3L
====

Simple, Fast 3D Library.

This is a little graphical library that I'm creating, that plugs right into SFML! I have copied SFML's simplicity so that it should be very easy for others to start coding in 3D!

This version is not finished.

My definition of Simple in SF3L:
 - Simple to use. This does not mean simple uses. I will try to add as much of OpenGL as I can, this includes the stencil buffer, fog, quadrics,...


====

TODO:

High priority:

 - Finalize all polygon rendering and handling
  - Utilize display lists -> Should changed positions force list recompilation? Nested Lists?
 - Add gluQuadric object handlers (Using RAII)
 - Add a view handler for the scene.

Low priority:

 - Work with per-vertex lighting: enabling/disabling system.
 - Insert 4-channel colors (RGBA) instead of 3-channel RGB
 - Finish the normal calculations for triangles and rectangles
 - Work on advanced lighting
 - Create quadric hierarchy
 - Add fog manager

... more coming, can't think of anything else right now...

Done:

Allow mesh to take all types of drawables.

