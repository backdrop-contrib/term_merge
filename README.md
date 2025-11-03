# Term Merge

When using taxonomy for free tagging purposes, it's easy to end up with several
terms having the same meaning. This may be due to spelling errors, or different
users simply making up synonymous terms as they go.

You, as an administrator, may then want to correct such errors or unify
synonymous terms, thereby pruning the taxonomy to a more manageable set. This
module allows you to merge multiple terms into one, while updating all fields
referring to those terms to refer to the replacement term instead.

Currently, the module only acts on:
 * fields of the following types: taxonomy term reference, entity reference, and
   other fields that correctly define their foreign keys
 * Views Taxonomy Term filter handlers
 * Redirects

The term merging may happen in 2 flavors. You can either manually indicate what
terms should be merged or you can use duplicate suggestion tool for this
purpose. This tool intends to scan your vocabulary and to detect such terms that
are likely to be duplicates. You will then only review the list of suggested
duplicates and will schedule for merging only those that actually are
duplicates. The heuristics through which duplicate tool determines potential
synonymous terms are made to be extensible by other modules. Refer to Term Merge
advanced help if you want to write a custom one, though the module itself ships
with the following heuristics:
* search by the same name
* search by the same description
* search by the same parent

You can indicate which specific heuristics should be used for searching
duplicates within the UI of duplicate suggestion tool.

## Integration

Currently module integrates with the following core and contributed modules:
 * Redirect module (in Backdrop core). During term merging you
   may set up SEO friendly redirects from the branch terms to point to the trunk
   term.
 * Views (in Backdrop core). If the branch terms are to be
   deleted after the merging process, you could end up having some Views filters
   to filter on no longer existing terms. Term Merge module, while merging
   terms, will update those filters to filter not on the branch term, but on the
   trunk term. This way you will not have senseless filters and will not have to
   update them manually.
 * Taxonomy Manager (contrib). A "Merge" button is provided in the Taxonomy
   Manager interface if this module is also enabled.

## Requirements

  - Taxonomy module enabled
  - [Plugin Manager](https://github.com/backdrop-contrib/plugin_manager)

## Installation and Usage

- Install this module using the [official Backdrop CMS instructions](https://backdropcms.org/guide/modules)
- Usage instructions can be [viewed and edited in the Wiki](https://github.com/backdrop-contrib/term_merge/wiki).

## Issues

 - Bugs and Feature requests should be reported in the [Issue Queue](https://github.com/backdrop-contrib/term_merge/issues).

## Current Maintainers

 - [Laryn Kragt Bakker](https://github.com/laryn).
 - Seeking co-maintainers

## Credits

 - Ported to Backdrop CMS by [Laryn Kragt Bakker](https://github.com/laryn).
 - Backdrop development is supported by [Aten Design Group](https://aten.io).
 - Maintainers on drupal.org include [aurelianzaha](https://www.drupal.org/u/aurelianzaha),
   [bucefal91](https://www.drupal.org/u/bucefal91),
   [daniel_j](https://www.drupal.org/u/daniel_j),
   [eli](https://www.drupal.org/u/eli),
   [g.i.joe](https://www.drupal.org/u/g.i.joe),
   [legolasbo](https://www.drupal.org/u/legolasbo),
   [nylin](https://www.drupal.org/u/nylin),
   [bleen](https://www.drupal.org/u/bleen).
 - Original authors: Max Nylin, and Oleksandr Trotsenko.

## License

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.
