<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd"><html><head><title>libm/sincos.c - platform/bionic - Git at Google</title><link rel="stylesheet" type="text/css" href="//www.google.com/css/go.css" /><link rel="stylesheet" type="text/css" href="/+static/prettify/prettify.vf-M93Ay4IiiWRQSJKPGWQ.cache.css" /><link rel="stylesheet" type="text/css" href="/+static/gitiles.sc1AQ5sZBtrPTWvjf0CFrw.cache.css" /><script src="/+static/prettify/prettify_compiled.0uRrzvY9oHqDRD2cidOlGg.cache.js" type="text/javascript"></script></head><body onload="prettyPrint()"><h1><img src="//www.google.com/images/logo_sm.gif" alt="Google" />Git</h1><div class="menu"> <a href="https://www.google.com/accounts/ServiceLogin?service=gerritcodereview&amp;continue=https://android.googlesource.com/login/platform/bionic/%2B/master/libm/sincos.c">Sign in</a> </div><div class="breadcrumbs"><a href="/?format=HTML">android</a> / <a href="/platform/bionic/">platform/bionic</a> / <a href="/platform/bionic/+/master">master</a> / <a href="/platform/bionic/+/master/">.</a> / <a href="/platform/bionic/+/master/libm">libm</a> / sincos.c</div><div class="sha1">blob: 891aa317fd7b0352510a50c0a36ba22659f19ccd [<a href="/platform/bionic/+log/master/libm/sincos.c">file history</a>]</div><pre class="git-blob prettyprint linenums lang-c">/*-
 * Copyright (c) 2010 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS&#39;&#39; AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */
#define _GNU_SOURCE 1
#include &lt;math.h&gt;

// Disable sincos optimization for all functions in this file,
// otherwise gcc would generate infinite calls.
// Refer to gcc PR46926.
// -fno-builtin-sin or -fno-builtin-cos can disable sincos optimization,
// but these two options do not work inside optimize pragma in-file.
// Thus we just enforce -O0 when compiling this file.
#pragma GCC optimize (&quot;O0&quot;)

void sincos(double x, double* p_sin, double* p_cos) {
  *p_sin = sin(x);
  *p_cos = cos(x);
}

void sincosf(float x, float* p_sinf, float* p_cosf) {
  *p_sinf = sinf(x);
  *p_cosf = cosf(x);
}

void sincosl(long double x, long double* p_sinl, long double* p_cosl) {
  *p_sinl = sinl(x);
  *p_cosl = cosl(x);
}
</pre><div class="footer">Powered by <a href="https://code.google.com/p/gitiles/">Gitiles</a></div></body></html>