.. Curse of the Blind documentation master file, created by
   sphinx-quickstart on Mon Jul 13 19:44:40 2020.

Curse of the Blind Documentation
================================

Welcome to the documentation for Curse of the Blind (CotB)!

.. toctree::
   :maxdepth: 2

   tutorials/tutorials
   todos

Introduction
============

Curse of the Blind is a project started in 2018 by `Preston Bridgers`_.
The project began as an idea for an old-school style ASCII game.
However, the project is now being pivoted to development as an
ASCII game engine. This documentation contains information and
:ref:`tutorials` to aid developers in its use.

.. _preston bridgers: https://www.linkedin.com/in/prestonbridgers

Equipment Needed
================

- A linux machine or virtual machine

Download
========

Dependencies (install these first using your package
manager of choice):

- libncurses-dev

.. note::

	Package names may change depending on the distribution
	of linux you are running. Currently nCurses, the only
	dependency, is extremely common and widely used. The
	above package name is taken from Debian/Ubuntu/Mint
	repositories.

The project can be cloned from its `gitlab page`_ using the
following command:

``git clone https://www.gitlab.com/prestonbridgers/curse-of-the-blind/``

.. _gitlab page: https://www.gitlab.com/prestonbridgers/curse-of-the-blind/

Usage
=====

After modifying the source code however you like, compile and run
the game by using the following command from the project's root
directory:

``cd ./src && make || make run``

.. note::

	The game will not run with the above command if there are errors
	during compilation.

FAQs
====

.. todo::

	Add FAQs to the FAQs section.

Support
=======

For support of any kind, contact me at:

- prestonbridgers@gmail.com

How to Contribute
=================

.. todo::

	Add content to the how to contribute section.

Licensing
=========

MIT License

Copyright (c) 2020 Preston C. Bridgers

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
