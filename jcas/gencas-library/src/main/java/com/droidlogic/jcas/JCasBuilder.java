package com.droidlogic.jcas;

import com.droidlogic.jcas.vendor.widevine.WidevineCasWrapperFactory;
import com.droidlogic.jcas.vendor.verimatrix.VerimatrixCasWrapperFactory;

public class JCasBuilder {
    public static final String mProjectConfig = "{ \"cas_vendor\": \"{vendor_name}\", \"android_api_level\": 36, \"product\": \"OTT\" }";

    /**
     * JCas can choose the CasWrapperFactory corresponding to the Cas vendor with Cas System ID.
     * Please create '{vendor}CasWrapperFactory' instance in createFactory function
     * ex) If WidevineCas case, new WidevineCasWrapperFactory(config)
     */
    public static CasWrapperFactory[] createFactory(String config) {
        return new CasWrapperFactory[] {
            new WidevineCasWrapperFactory(config),
            new VerimatrixCasWrapperFactory(config)
        };
    }

    /**
     * Get project init configuration.
     */
    public static String getProjectConfig() {
        return mProjectConfig;
    }
}
