# $Id: Makefile.PL,v 1.6 2005/02/10 12:27:15 mrodrigu Exp $
# tool installation part shamelessly lifted from YAML's Makefile.PL

use ExtUtils::MakeMaker;

my @programs;

push(@programs,"xml_pp");
push(@programs,"xml_grep");
push(@programs,"xml_split");
push(@programs,"xml_merge");
push(@programs,"xml_spellcheck");

WriteMakefile(
    NAME	     => 'XML::Twig',
    ABSTRACT     => 'XML, The Perl Way',
    AUTHOR       => 'Michel Rodriguez <mirod@xmltwig.com>',
    EXE_FILES    => [ map {"tools/$_/$_"} @programs],
    VERSION_FROM => 'Twig.pm', # finds $VERSION
    PREREQ_PM    => { 'XML::Parser' => '2.23' },
    dist         => { COMPRESS    => 'gzip -9f',
                      SUFFIX	     => 'gz',
                    },
    'depend'     => { 'Twig.pm' => "FORCE\n\techo \"building Twig.pm\"\n\t\$(PERL) speedup Twig.pm.slow > Twig.pm\n\t\$(PERL) check_optional_modules",
		                  'FORCE'   => '',
									  },
);

